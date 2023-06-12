interface MyInterface {
    public void method1();
    public void method2();
}

class Everything implements MyInterface {
    private int x = 0;
    private static double y = 42.54;

    public void method1() {
        System.out.println("Implementation of method1");
    }
    public void method2() {
        System.out.println("Implementation of method2");
    }
    public static void main(String[] args) throws Exception {
        Everything obj = new Everything();
        obj.method1();
        obj.method2();
        obj.canThrowException(false);
    }

    public int canThrowException(boolean willThrow) throws Exception {
        if (willThrow)
            throw new Exception("Exception");
        else
        return 0;
    }
}