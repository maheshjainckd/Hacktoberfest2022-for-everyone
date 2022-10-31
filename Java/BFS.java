//Directed
    public static void BFS(ArrayList<ArrayList<Integer>> adj,int V)
    {
        boolean[] visited=new boolean[V+1];
        for(int i=1;i<=V;i++)
        {
            visited[i]=false;
        }

        LinkedList<Integer> queue=new LinkedList<Integer>();
//        Source Vertex
        int s=0;
        visited[s]=true;
        queue.add(s);

        while(queue.size()!=0)
        {
            s=queue.poll();
            System.out.print(s+" ");

         Iterator<Integer> i=adj.get(s).listIterator();
          while (i.hasNext())
          {
              int newNode=i.next();
              if(visited[newNode]==false)
              {
                  visited[newNode]=true;
                  queue.add(newNode);
              }
          }

        }
    }
    
    
    
    //Undirected
    public static void BFS(ArrayList<ArrayList<Integer>> adj,int V)
    {
        boolean[] visited=new boolean[V+1];
        for(int i=1;i<=V;i++)
        {
            visited[i]=false;
        }

        LinkedList<Integer> queue=new LinkedList<Integer>();
//        Source Vertex
        int s=1;
        visited[s]=true;
        queue.add(s);

        while(queue.size()!=0)
        {
            s=queue.poll();
            System.out.print(s+" ");

            for(int i=0;i<adj.get(s).size();i++)
            {
                int newNode=adj.get(s).get(i);
                if(visited[newNode]==false)
                {
                    visited[newNode]=true;
                    queue.add(newNode);
                }
            }
        }
    }
