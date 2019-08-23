import java.util.Scanner;

public class Maximum_Subsequence_Sum{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int K = in.nextInt();
        int []a = new int[K];
        for (int i = 0; i < K; i++) {
            a[i] = in.nextInt();
        }
        System.out.println(max_dg(a));
    }
    public static int max_dg(int[] a)
    {
        int start=0, finish = 0;
        int maxsum = 0;
        int temp_sum = 0;
        int flag = 0;

        //数组中含有正数
        for (int i = 0,j=0; j<a.length; j++)
        {
            temp_sum += a[j];
            if (temp_sum > maxsum)
            {
                maxsum = temp_sum;
                start=i+1;
                finish = j+1;
            }
            else if (temp_sum<0){
                temp_sum = 0;
                i=j+1;
            }
        }

        //在该循环内判断序列中是否存在正数
        for (int i = 0; i<a.length; i++)
            if (a[i]>0) flag = 1;      //用flag标记，若存在正数则为1

        //若不存在正数，则输出0和首尾元素
        if (flag == 0)
        {
            maxsum = 0; start = 1; finish = a.length;
            return 0;
        }
        return maxsum;
    }
}
