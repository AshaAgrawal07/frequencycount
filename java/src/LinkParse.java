
import com.mashape.unirest.http.HttpResponse;
import com.mashape.unirest.http.Unirest;
import com.mashape.unirest.http.exceptions.UnirestException;

import java.net.MalformedURLException;
import java.net.URL;

/**
 * Created by zilles on 9/19/17.
 */
public class LinkParse {

    private static final int STATUS_OK = 200;

    public static String parse (String urlToParse) {
        String url = urlToParse;

        // Make an HTTP request to the above URL
        try {
            String x = makeApiRequest(url);
            if (x != null) {
                return x;
            }
        } catch (UnirestException e) {
//            e.printStackTrace();
            return ("Network not responding");
        } catch (MalformedURLException e) {
            return ("Bad URL: " + url);
        }
        return null;
    }

    static String makeApiRequest(String url) throws UnirestException, MalformedURLException {
        final HttpResponse<String> stringHttpResponse;

        // This will throw MalformedURLException if the url is malformed.
        new URL(url);

        stringHttpResponse = Unirest.get(url).asString();
        // Check to see if the request was successful; if so, convert the payload JSON into Java objects
        if (stringHttpResponse.getStatus() == STATUS_OK) {
            String file = stringHttpResponse.getBody();
            return file;
        }
        return null;
    }
}