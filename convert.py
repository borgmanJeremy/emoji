from bs4 import BeautifulSoup


def print_code():
    print("")

def print_as_enum(name, set):
    print("class enum {} {{".format(name))
    for item in set:
        print("\t{},".format(item))
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
            code = inner
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
            name = ""
            code = "" 
            changed = False

print_as_enum("Category", category_list)
print_as_enum("Subcategory", subcategory_list)
