/**
 * AUTHORS: <Raphael Gozlan, Sarah Hananayev>
 *
 * Date: 2020-02
 */

#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;


TEST_CASE("Test replacement of v and w") {
    string text = " v we have to reviwe this play rewind";
            CHECK(find(text, "w") == string("v"));
            CHECK(find(text, "W") == string("v"));
            CHECK(find(text, "reviwe") == string("reviwe"));
            CHECK(find(text, "rewiwe") == string("reviwe"));
            CHECK(find(text, "rewiwe") == string("reviwe"));
            CHECK(find(text, "revive") == string("reviwe"));
            CHECK(find(text, "rewind") == string("rewind"));
            CHECK(find(text, "revind") == string("rewind"));
            CHECK(find(text, "hawe") == string("have"));
            CHECK(find(text, "ve") == string("we"));
            CHECK(find(text, "we") == string("we"));
}

TEST_CASE("Test replacement of p and b") {
    string text = "xxx happy yyy";
            CHECK(find(text, "happy") == string("happy"));
            CHECK(find(text, "habby") == string("happy"));
            CHECK(find(text, "hapby") == string("happy"));
            CHECK(find(text, "habpy") == string("happy"));
    /* Add more checks here */
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
            CHECK(find(text, "happi") == string("Happi"));
            CHECK(find(text, "Happi") == string("Happi"));
            CHECK(find(text, "HAPPI") == string("Happi"));
            CHECK(find(text, "HaPpI") == string("Happi"));
}
TEST_CASE("Edge Case Test") {
    string text = "Hello     World";

            CHECK(find(text, "     Hello") == string("Hello"));
            CHECK(find(text, "Hello     ") == string("Hello"));
            CHECK(find(text, "World     ") == string("World"));
            CHECK(find(text, "     World") == string("World"));

}