public class Solution {
    
    private long mod = 1000000007;
    
    public int nchoc(int A, ArrayList<Integer> B) {
        PriorityQueue<Integer>  pq = new PriorityQueue<Integer>(
            new Comparator<Integer>(){
                @Override
                public int compare(Integer i1, Integer i2) {
                    return i2.compareTo(i1);
                }
            });
        for(Integer i : B)  pq.add(i);
        long score = 0;
        while(A-- > 0) {
            int top = pq.poll();
            score =(score + top) % mod;
            pq.add(top/2);
    
        }
        return (int)score;
    }
}
