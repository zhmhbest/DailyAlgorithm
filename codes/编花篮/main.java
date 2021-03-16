public class main {
    public static void test(char ch0, char ch1, int length) {
        // char[] chs = (1 == length % 2) ? new char[] { ch0, ch1 } : new char[] { ch1, ch0 };
        char[] chs = new char[] { ch0, ch1 };
        float center = (float) (length) / 2;

        for (int row = 0; row < length; row++) {
            for (int col = 0; col < length; col++) {
                if ((0 == row || (length - 1) == row) && (0 == col || (length - 1) == col)) {
                    System.out.print(' ');
                } else {
                    float dR = (float) Math.abs(row + 0.5 - center);
                    float dC = (float) Math.abs(col + 0.5 - center);
                    int distance = (int) Math.ceil(Math.max(dR, dC));
                    System.out.print(chs[distance % 2]);
                }
            }
            System.out.print('\n');
        }
    }

    public static void main(String[] args) {
        test('B', 'A', 11);
        test('@', 'W', 5);
    }
}