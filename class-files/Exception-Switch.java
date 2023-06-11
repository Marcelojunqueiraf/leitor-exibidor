class ExceptionAndSwitch {
    public static void main(String[] args) throws Exception {
        ExceptionAndSwitch e = new ExceptionAndSwitch();
        e.throwsException(0);
    }

    public double usesSwitch(int x) {
        switch (x) {
            case 1:
                return 1.0;
            case 2:
                return 2.0;
            default:
                return 0.0;
        }
    }

    public double throwsException(int x) throws Exception {
        if (usesSwitch(x) == 0) {
            throw new Exception("x is 0");
        } else {
            return usesSwitch(x);
        }
    }
}