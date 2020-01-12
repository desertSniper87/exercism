class Twofer {
    String twofer(String name) {
        if (name == null) {
            return twofer();
        }
        return "One for " + name + ", one for me.";
    }

    String twofer() {
        return twofer("you");
    }
}
