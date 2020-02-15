public class Solution {
    
    Map<Integer, Integer> m;
    List<Integer> q;
    int capacity;
    
    public Solution(int capacity) {
        this.m = new HashMap<Integer, Integer>();
        this.capacity = capacity;
        this.q = new ArrayList<Integer>();
    }
    
    public int get(int key) {
        if(m.containsKey(key))  {
            int y = m.get(key);
            for(int i = q.size()-1; i >= 0; --i) {
                if(q.get(i) == key) {
                    q.remove(i);                
                }
            }
            q.add(0, key);
            
            if(q.size() > this.capacity) {
                m.remove(q.get(q.size()-1));
                q.remove(q.size()-1);
            }
            return y;
        }
        return -1;
    }
    
    public void set(int key, int value) {
        m.put(key, value);
        for(int i = q.size()-1; i >= 0; --i) {
            if(q.get(i) == key) {
                q.remove(i);                
            }
        }
        q.add(0, key);
        if(q.size() > this.capacity) {
            m.remove(q.get(q.size()-1));
            q.remove(q.size()-1);
        }
    }
}
