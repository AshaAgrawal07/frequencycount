//
// Created by Asha Agrawal on 3/5/2018.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"



class FrequencyCounterTest {

    TEST_CASE ("Invalid Input tests", "[checkValidityAndUpdate]")
    {
        SECTION ("null test")
        {
            FrequencyCounter.checkValidityAndUpdate(null);
            REQUIRE ("INVALID INPUT");
        }
    }
    SECTION("emptyTest")
    {

        FrequencyCounter.checkValidityAndUpdate("");
        REQUIRE ("INVALID INPUT");
    }

    @Test
public

    void emptySpaceTest() {
        thrown.expect(IllegalArgumentException.
        class);
        thrown.expectMessage("INVALID INPUT");
        FrequencyCounter.checkValidityAndUpdate(" ");
    }

    @Test
public

    void emptyMultipleSpacesTest() {
        thrown.expect(IllegalArgumentException.
        class);
        thrown.expectMessage("INVALID INPUT");
        FrequencyCounter.checkValidityAndUpdate("    ");
    }

    @Test
public

    void emptyTabTest() {
        thrown.expect(IllegalArgumentException.
        class);
        thrown.expectMessage("INVALID INPUT");
        FrequencyCounter.checkValidityAndUpdate("  ");
    }

    @Test
public

    void emptyMultipleTabTest() {
        thrown.expect(IllegalArgumentException.
        class);
        thrown.expectMessage("INVALID INPUT");
        FrequencyCounter.checkValidityAndUpdate("          ");
    }

    @Test
public

    void emptyLineTest() {
        thrown.expect(IllegalArgumentException.
        class);
        thrown.expectMessage("INVALID INPUT");
        FrequencyCounter.checkValidityAndUpdate("\n");
    }

    @Test
public

    void onlyPunctuationTest() {
        assertEquals("Dictionary updated successfully", FrequencyCounter.checkValidityAndUpdate(".>'/|+=-"));
    }

    @Test
public

    void punctuationWithSpacesTest() {
        assertEquals("Dictionary updated successfully",
                     FrequencyCounter.checkValidityAndUpdate("   .>' /   |+=-   "));
    }
}
