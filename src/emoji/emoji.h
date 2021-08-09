//
// Created by jeremy on 8/8/21.
//

#ifndef EMOJI_EMOJI_H
#define EMOJI_EMOJI_H

#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
namespace Emoji{
    std::unordered_set<unsigned int> search_keys(std::string const &search_term);

    enum class Category {
        ACTIVITIES,
        PEOPLE_AND_BODY,
        SMILEYS_AND_EMOTION,
        FLAGS,
        COMPONENT,
        SYMBOLS,
        FOOD_AND_DRINK,
        ANIMALS_AND_NATURE,
        TRAVEL_AND_PLACES,
        OBJECTS,
        };

    enum class Subcategory {
        ARTS_AND_CRAFTS,
        FACE_NEUTRAL_SKEPTICAL,
        ALPHANUM,
        PERSON_RESTING,
        HAND_PROP,
        KEYCAP,
        PLACE_OTHER,
        MONKEY_FACE,
        PUNCTUATION,
        MAIL,
        OFFICE,
        PLACE_RELIGIOUS,
        PERSON_GESTURE,
        TRANSPORT_SIGN,
        FACE_UNWELL,
        PERSON_SYMBOL,
        SCIENCE,
        SUBDIVISION_FLAG,
        AWARD_MEDAL,
        FACE_HAND,
        TRANSPORT_GROUND,
        RELIGION,
        FOOD_MARINE,
        CLOTHING,
        FACE_SLEEPY,
        WRITING,
        AV_SYMBOL,
        PLACE_GEOGRAPHIC,
        EMOTION,
        SPORT,
        FOOD_ASIAN,
        FACE_COSTUME,
        FACE_AFFECTION,
        FACE_TONGUE,
        FOOD_SWEET,
        ARROW,
        TRANSPORT_AIR,
        HAND_FINGERS_CLOSED,
        TRANSPORT_WATER,
        FOOD_VEGETABLE,
        FACE_GLASSES,
        FACE_HAT,
        LIGHT_AND_VIDEO,
        MONEY,
        TIME,
        DRINK,
        FAMILY,
        MUSIC,
        HAND_FINGERS_PARTIAL,
        FOOD_PREPARED,
        PLANT_FLOWER,
        ANIMAL_MAMMAL,
        PERSON_FANTASY,
        FOOD_FRUIT,
        COUNTRY_FLAG,
        GAME,
        HOTEL,
        ANIMAL_BUG,
        ANIMAL_MARINE,
        SOUND,
        PLACE_BUILDING,
        MUSICAL_INSTRUMENT,
        PERSON,
        TOOL,
        LOCK,
        FACE_NEGATIVE,
        ANIMAL_BIRD,
        CURRENCY,
        CAT_FACE,
        HAND_FINGERS_OPEN,
        ANIMAL_REPTILE,
        BODY_PARTS,
        PERSON_ROLE,
        PERSON_ACTIVITY,
        OTHER_OBJECT,
        EVENT,
        BOOK_PAPER,
        GEOMETRIC,
        HOUSEHOLD,
        HAND_SINGLE_FINGER,
        SKY_AND_WEATHER,
        FACE_CONCERNED,
        HAIR_STYLE,
        ZODIAC,
        DISHWARE,
        GENDER,
        HANDS,
        PLACE_MAP,
        FLAG,
        ANIMAL_AMPHIBIAN,
        PERSON_SPORT,
        FACE_SMILING,
        MATH,
        PLANT_OTHER,
        MEDICAL,
        PHONE,
        WARNING,
        COMPUTER,
        OTHER_SYMBOL,
        };

    struct Emoji {
        Emoji(Category category, Subcategory subcategory, std::string description, std::string code) :category(category), subcategory(subcategory), description(description), code(code)  {}

        Category const category;
        Subcategory const subcategory ;
        std::string const description;
        std::string const code;
    };

    extern std::vector<Emoji> emoji_list;
    extern std::unordered_map<std::string, Category> category_list;
    extern std::unordered_map<std::string, Subcategory> subcategory_list;
}
#endif //EMOJI_EMOJI_H
