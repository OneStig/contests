public class Dec15 {
    public static void main(String[] args) {
        /*
         * int[] arr1 = { 1, 2, 3, 4, 5, 6, 7, 8 }; printArr(arr1);
         * printArr(change(arr1));
         * 
         * int[] arr2 = { 2, 4, 4, 2, 1, 6, 71, 81 }; printArr(arr2);
         * printArr(change(arr2));
         */
        int[] arr3 = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
        printArr(arr3);
        printArr(change(arr3));
    }

    public static int[] change(int[] arr) {
        int[] newArr = new int[arr.length];
        for (int i = 0; i < arr.length - 1; i++) {
            if (arr[i] % 2 == 0) {
                newArr[i] = arr[i] * 2;
            } else if (arr[i] % 3 == 0) {
                newArr[i] = arr[i] * 3;
            } else {
                newArr[i] = arr[i];
            }
        }
        return newArr;
    }

    public static void printArr(int[] arr) {
        System.out.print("{ ");

        for (int i = 0; i < arr.length - 2; i++) {
            System.out.print(i + ", ");
        }
        System.out.println(arr[arr.length - 1] + " }");
    }
}public class Dec15 {
    public static void main(String[] args) {
        /*
         * int[] arr1 = { 1, 2, 3, 4, 5, 6, 7, 8 }; printArr(arr1);
         * printArr(change(arr1));
         * 
         * int[] arr2 = { 2, 4, 4, 2, 1, 6, 71, 81 }; printArr(arr2);
         * printArr(change(arr2));
         */
        int[] arr3 = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
        printArr(arr3);
        printArr(change(arr3));
    }

    public static int[] change(int[] arr) {
        int[] newArr = new int[arr.length];
        for (int i = 0; i < arr.length - 1; i++) {
            if (arr[i] % 2 == 0) {
                newArr[i] = arr[i] * 2;
            } else if (arr[i] % 3 == 0) {
                newArr[i] = arr[i] * 3;
            } else {
                newArr[i] = arr[i];
            }
        }
        return newArr;
    }

    public static void printArr(int[] arr) {
        System.out.print("{ ");

        for (int i = 0; i < arr.length - 2; i++) {
            System.out.print(i + ", ");
        }
        System.out.println(arr[arr.length - 1] + " }");
    }
}