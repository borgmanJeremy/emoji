//
// Created by jeremy on 8/8/21.
//

#ifndef EMOJI_EMOJI_H
#define EMOJI_EMOJI_H

#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <map>
#include "json.hpp"


namespace Emoji {
    using json = nlohmann::json;

    struct Emoji {
        std::string hexcode;
        std::string annotation;
    };

    class EmojiList {
    public:
        EmojiList();

        void find_matches(std::string const &term);

        std::vector<Emoji> emoji_list;

        std::vector<size_t> filter_results;
        std::string path_prefix;
    private:
        std::vector<std::string> category_lookup;
        std::vector<std::string> subcategory_lookup;
        std::vector<std::string> tags;


        std::map<size_t, std::vector<size_t>> category_emoji_relation;
        std::map<size_t, std::vector<size_t>> subcategory_emoji_relation;
        std::map<size_t, std::vector<size_t>> tag_emoji_relation;



    };

}
#endif //EMOJI_EMOJI_H
