from bs4 import BeautifulSoup


def print_code():
    print("")

def print_as_enum(name, set):
    print("enum class {} {{".format(name))
    for item in set:
        print("\t{},".format(item))
    print("};")

def print_as_unordered_map(input_list, key, class_name, map_name):
    list_dict = list() 
    for item in input_list:
        list_dict.append({"string": item[key].lower(), "enum":format_category(item[key])})
    result = [dict(tupleized) for tupleized in set(tuple(item.items()) for item in list_dict)] 

    print('std::unordered_map<std::string, {}> {} = {{'.format(class_name, map_name))
    for item in result:
        print('{{ "{}", {}::{} }},'.format(item["string"], class_name, item["enum"]))
    print('};')



def print_as_vector(input_list):
    print('std::vector<Emoji> emoji_list = {')
    for item in input_list:
        print('Emoji {{ Category::{}, Subcategory::{}, "{}", "{}" }},'.format(format_category(item["category"]), format_category(item["subcategory"]), item["description"], item["code"]))
    print("};")

def format_category(input):
    formatted = input.replace("&", "and")
    formatted = formatted.replace(" ", "_")
    formatted = formatted.replace("-", "_")
    formatted = formatted.upper()
    return formatted


category = ""
subcategory = ""
code = ""
name = ""
changed = False
category_list =set() 
subcategory_list =set() 
code_list = list()
with open("output_no_link.html","r") as file:
    for line in file:
        # print(line)
        if "bighead" in line:
            soup = BeautifulSoup(line, features="html.parser")
            inner = soup.find('th').text
            category = inner
            subcategory=""
            name=""
            code=""
            changed = True

        if "mediumhead" in line:
            soup = BeautifulSoup(line, features="html.parser")
            inner = soup.find('th').text
            subcategory = inner
            name=""
            code=""
            changed = True

        if "code" in line:
            soup = BeautifulSoup(line, features="html.parser")
            inner = soup.find('td').text
            code = inner.split(" ", 1)[0]
            code = code.replace("U+",'')
            length = len(code)
            code = "\\U" + "0"*(8-length) + code
            changed = True

        if "name" in line:
            soup = BeautifulSoup(line, features="html.parser")
            inner = soup.find('td').text
            name = inner
            changed = True

        if category !="" and subcategory !="" and code !="" and name !="" and changed == True:
            #print("category: {}, subcategory: {}, name: {}, code: {}".format(category, subcategory, name, code))
            category_list.add(format_category(category))
            subcategory_list.add(format_category(subcategory))
            code_list.append({"category": category, "subcategory": subcategory, "description": name.lower(), "code": code})
            name = ""
            code = "" 
            changed = False


#print_as_enum("Category", category_list)
#print_as_enum("Subcategory", subcategory_list)
print_as_vector(code_list)
#print_as_unordered_map(code_list,"category", "Category", "category_list")
#print_as_unordered_map(code_list,"subcategory", "Subcategory", "subcategory_list")