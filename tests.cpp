#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "HTable.h"

HTable *h1 = new HTable();

TEST_CASE("hash function"){
    CHECK(h1->hash("a") == 97);
    CHECK(h1->hash("macadamia") == 10);
    CHECK(h1->hash("great") == 31);
    CHECK(h1->hash("sleep") == 37);
}

TEST_CASE("insert function"){
    h1->insert("a");
    CHECK(h1->toStringSimplified("a") == "97: a-->nullptr");
    h1->insert("macadamia");
    CHECK(h1->toStringSimplified("macadamia") == "10: macadamia-->nullptr");
    h1->insert("great");
    CHECK(h1->toStringSimplified("great") == "31: great-->nullptr");
    h1->insert("sleep");
    CHECK(h1->toStringSimplified("sleep") == "37: sleep-->nullptr");
}

TEST_CASE("insert function - duplicate"){
    h1->insert("a");
    CHECK(h1->toStringSimplified("a") == "97: a-->a-->nullptr");
    h1->insert("a");
    CHECK(h1->toStringSimplified("a") == "97: a-->a-->a-->nullptr");
    h1->insert("a");
    CHECK(h1->toStringSimplified("a") == "97: a-->a-->a-->a-->nullptr");
}

TEST_CASE("has_key function"){
    CHECK(h1->has_key("a") == true);
    CHECK(h1->has_key("great") == true);
    CHECK(h1->has_key("a ") == false);
    CHECK(h1->has_key("a-->") == false);
    CHECK(h1->has_key(" a") == false);
}

TEST_CASE("Empty string"){
    CHECK(h1->hash("") == 0);
    h1->insert("");
    CHECK(h1->toStringSimplified("") == "0: -->nullptr");
}

TEST_CASE("Space"){
    CHECK(h1->hash(" ") == 32);
    h1->insert(" ");
    CHECK(h1->toStringSimplified(" ") == "32:  -->nullptr");
}
