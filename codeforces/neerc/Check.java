/******************************************************************/
/* ACM ICPC 2014-2015, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 8, 2014                                */
/******************************************************************/
/* Problem F. Fragmentation                                       */
/*                                                                */
/* Original idea         Georgiy Korneev                          */
/* Problem statement     Pavel Mavrin                             */
/* Test set              Pavel Mavrin                             */
/******************************************************************/
/* Checker                                                        */
/*                                                                */
/* Author                Pavel Mavrin                             */
/******************************************************************/

import ru.ifmo.testlib.Checker;
import ru.ifmo.testlib.InStream;
import ru.ifmo.testlib.Outcome;

import java.util.Arrays;
import java.util.Comparator;

import static ru.ifmo.testlib.Outcome.Type.*;

public class Check implements Checker {
    public Outcome outcome(Outcome.Type type, final String format, final Object... args) {
        return new Outcome(type, String.format(format, args));
    }

    public Outcome test(InStream inf, InStream ouf, InStream ans) {
        final int n = inf.nextInt();
        final int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = inf.nextInt();
        }

        int m = ouf.nextInt();
        if (m <= 0 || m > n) {
            return outcome(WA, "Invalid number of segments: %d (n = %d)", m, n);
        }

        int[] p = new int[m];
        int[][] segments = new int[m][2];
        int s = 0;
        for (int i = 0; i < m; i++) {
            p[i] = ouf.nextInt();
            if (p[i] <= 0 || p[i] > n) return new Outcome(WA, "Invalid length of segment: " + p[i]);
            segments[i][0] = s;
            s += p[i];
            segments[i][1] = s;
        }
        if (s != n) return new Outcome(WA, "Total length is not N");

        Arrays.sort(segments, Comparator.<int[]>comparingInt(o -> a[o[0]]).thenComparingInt(o -> a[o[1] - 1]));
        int[] aa = new int[n];
        int k = 0;
        for (int[] segment : segments) {
            for (int i = segment[0]; i < segment[1]; i++) {
                aa[k++] = a[i];
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (aa[i] > aa[i + 1]) return new Outcome(WA, "Array is not sorted");
        }

        int ja = ans.nextInt();
        if (ja < m) {
            return outcome(WA, "Not optimal solution: %d instead of %d", m, ja);
        }
        if (ja > m) {
            return outcome(FAIL, "Jury has not optimal solution: %d instead of %d", ja, m);
        }
        return outcome(OK, "%d", ja);
    }
}

