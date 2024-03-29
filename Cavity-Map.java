import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'cavityMap' function below.
     *
     * The function is expected to return a STRING_ARRAY.
     * The function accepts STRING_ARRAY grid as parameter.
     */

    public static List<String> cavityMap(List<String> grid) {
    // Write your code here
        for (int i = 1; i < grid.size() - 1; ++i) {
            for (int k = 1; k < grid.get(i).length() - 1; ++k) {
                if (grid.get(i).charAt(k) > grid.get(i - 1).charAt(k) &&
                    grid.get(i).charAt(k) > grid.get(i + 1).charAt(k) &&
                    grid.get(i).charAt(k) > grid.get(i).charAt(k - 1) &&
                    grid.get(i).charAt(k) > grid.get(i).charAt(k + 1)) {
                    char[] chars = grid.get(i).toCharArray();
                    chars[k] = 'X';
                    grid.set(i, new String(chars));
                }
            }
        }

        return grid;
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        List<String> grid = IntStream.range(0, n).mapToObj(i -> {
            try {
                return bufferedReader.readLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        })
            .collect(toList());

        List<String> result = Result.cavityMap(grid);

        bufferedWriter.write(
            result.stream()
                .collect(joining("\n"))
            + "\n"
        );

        bufferedReader.close();
        bufferedWriter.close();
    }
}
