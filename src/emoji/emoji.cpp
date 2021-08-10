//
// Created by jeremy on 8/9/21.
//
#include "emoji.h"
#include <iostream>
#include <sstream>

namespace Emoji {

    template<typename T>
    void add_unique(std::vector<T> &input_vec, T const &to_add) {
        if (std::find(begin(input_vec), end(input_vec), to_add) == std::end(input_vec)) {
            input_vec.push_back(to_add);
        }
    }

    template<typename T>
    void add_relation(std::map<size_t, std::vector<size_t>> &relation, std::vector<T> const &sorted_index,
                      T const &index_term, size_t new_term_index) {
        auto index_it = std::lower_bound(sorted_index.begin(), sorted_index.end(), index_term);

        // First make sure the index term we want to link to is actually a member of the index
        if (index_it != std::end(sorted_index)){
            size_t index = index_it - sorted_index.begin();

            // Then check if the relation table already has a key pointing to the index
            if (relation.find(index) != relation.end()){
                // Since the relation table already has the index, we can add the new term
                relation[index].push_back(new_term_index);
            }
            else{
                // Since we did not find an entry in the relation table, we need to create a new one
                 std::vector<size_t> new_vec;
                 new_vec.push_back(new_term_index);
                 relation.emplace(index, new_vec);
            }
        }
    }

    std::vector<std::string> tokenize(std::string const &input, char token) {
        std::vector<std::string> tokens;
        std::stringstream tokenizer(input);
        std::string temp;
        while (getline(tokenizer, temp, token)) {
            temp.erase(remove_if(temp.begin(), temp.end(), isspace), temp.end());
            tokens.push_back(temp);
        }
        return tokens;
    }

    EmojiList::EmojiList(std::string index) {
        std::ifstream i("/home/jeremy/github/emoji/assets/index.json");
        json j;
        i >> j;

        // Build indices
        for (auto &emoji: j) {
            add_unique(category_lookup, emoji["group"].get<std::string>());
            add_unique(subcategory_lookup, emoji["subgroups"].get<std::string>());

            auto tag_list = tokenize(emoji["tags"].get<std::string>(), ',');
            for (auto const &tag: tag_list) {
                add_unique(tags, tag);
            }
            tag_list = tokenize(emoji["openmoji_tags"].get<std::string>(), ',');
            for (auto const &tag: tag_list) {
                add_unique(tags, tag);
            }
        }
        std::sort(category_lookup.begin(), category_lookup.end());
        std::sort(subcategory_lookup.begin(), subcategory_lookup.end());
        std::sort(tags.begin(), tags.end());

        //Build emoji list
        for (auto &emoji: j) {
            emoji_list.emplace_back(Emoji{emoji["hexcode"], emoji["annotation"]});
            add_relation(category_emoji_relation, category_lookup, emoji["group"].get<std::string>(), emoji_list.size());
        }

    }

}

