class Hamming {
    private int distance = 0;
    Hamming(String leftStrand, String rightStrand) throws IllegalArgumentException{
        int l = leftStrand.length();
        int r = rightStrand.length();

        if (l != r) {
            if (l == 0)
                throw new IllegalArgumentException("left strand must not be empty.");
            else if (r == 0)
                throw new IllegalArgumentException("right strand must not be empty.");
            else
                throw new IllegalArgumentException("leftStrand and rightStrand must be of equal length.");
        }
        else {
            for (int i=0;i<l;i++) {
                if ( leftStrand.charAt(i) != rightStrand.charAt(i)){
                    this.distance++;
                }
            }
        }
    }

    int getHammingDistance() {
        return this.distance;
    }
}
