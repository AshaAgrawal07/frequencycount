import org.junit.Test;
import org.junit.Rule;
import org.junit.rules.ExpectedException;

import static org.junit.Assert.*;
public class FrequencyCounterTest {

    @Rule
    public ExpectedException thrown = ExpectedException.none();

    @Test
    public void nullTest() {
        thrown.expect(IllegalArgumentException.class);
        thrown.expectMessage("INVALID INPUT");
        FrequencyCounter.checkValidityAndUpdate(null);
    }

    @Test
    public void emptyTest() {
        thrown.expect(IllegalArgumentException.class);
        thrown.expectMessage("INVALID INPUT");
        FrequencyCounter.checkValidityAndUpdate("");
    }

    @Test
    public void emptySpaceTest() {
        thrown.expect(IllegalArgumentException.class);
        thrown.expectMessage("INVALID INPUT");
        FrequencyCounter.checkValidityAndUpdate(" ");
    }

    @Test
    public void emptyMultipleSpacesTest() {
        thrown.expect(IllegalArgumentException.class);
        thrown.expectMessage("INVALID INPUT");
        FrequencyCounter.checkValidityAndUpdate("    ");
    }

    @Test
    public void emptyTabTest() {
        thrown.expect(IllegalArgumentException.class);
        thrown.expectMessage("INVALID INPUT");FrequencyCounter.checkValidityAndUpdate("  ");
    }

    @Test
    public void emptyMultipleTabTest() {
        thrown.expect(IllegalArgumentException.class);
        thrown.expectMessage("INVALID INPUT");
        FrequencyCounter.checkValidityAndUpdate("          ");
    }

    @Test
    public void emptyLineTest() {
        thrown.expect(IllegalArgumentException.class);
        thrown.expectMessage("INVALID INPUT");
        FrequencyCounter.checkValidityAndUpdate("\n");
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
