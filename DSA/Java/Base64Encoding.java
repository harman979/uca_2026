class Base64Encoding {

    private static final char[] TABLE =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/".toCharArray();

    public static String encode(String input) {
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < input.length(); i += 3) {
            int b1 = input.charAt(i);
            int b2 = i + 1 < input.length() ? input.charAt(i + 1) : 0;
            int b3 = i + 2 < input.length() ? input.charAt(i + 2) : 0;

            int first = (b1 >> 2) & 63;
            int second = ((b1 & 3) << 4) | ((b2 >> 4) & 15);
            int third = ((b2 & 15) << 2) | ((b3 >> 6) & 3);
            int fourth = b3 & 63;

            result.append(TABLE[first]);
            result.append(TABLE[second]);

            if (i + 1 < input.length()) {
                result.append(TABLE[third]);
            } else {
                result.append('=');
            }

            if (i + 2 < input.length()) {
                result.append(TABLE[fourth]);
            } else {
                result.append('=');
            }
        }

        return result.toString();
    }

    public static void main(String[] args) {
        System.out.println(encode("Man"));
        System.out.println(encode("Ma"));
        System.out.println(encode("A"));
        System.out.println(encode("Cat"));
        System.out.println(encode("Hello World"));
        System.out.println(encode(""));
    }
}
