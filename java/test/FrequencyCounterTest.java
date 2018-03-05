import org.junit.Test;
import org.junit.rules.ExpectedException;

import static org.junit.Assert.*;
public class FrequencyCounterTest {

    @Test
    public void nullTest() {
        assertEquals("Invalid string input", FrequencyCounter.checkValidityAndUpdate(null));
    }

    @Test
    public void emptyTest() {
        assertEquals("Invalid string input", FrequencyCounter.checkValidityAndUpdate(""));
    }

    @Test
    public void emptySpaceTest() {
        assertEquals("Invalid string input", FrequencyCounter.checkValidityAndUpdate(" "));
    }

    @Test
    public void emptyMultipleSpacesTest() {
        assertEquals("Invalid string input", FrequencyCounter.checkValidityAndUpdate("    "));
    }

    @Test
    public void emptyTabTest() {
        assertEquals("Invalid string input", FrequencyCounter.checkValidityAndUpdate("  "));
    }

    @Test
    public void emptyLineTest() {
        assertEquals("Invalid string input", FrequencyCounter.checkValidityAndUpdate("\n"));
    }

    @Test
    public void onlyPunctuationTest() {
        assertEquals("Dictionary updated successfully", FrequencyCounter.checkValidityAndUpdate(".>'/|+=-"));
    }

    @Test
    public void punctuationWithSpacesTest() {
        assertEquals("Dictionary updated successfully",
                FrequencyCounter.checkValidityAndUpdate("   .>' /   |+=-   "));
    }
}
