import java.util.Arrays;
import java.util.Scanner;
public class Dijkstra
{
static int n,cost[][],i,j,u,dist[],src;
void dij(int src,int cost[][],int dist[],int n)
{
int visited[],min;
visited=new int[n];
for(i=0;i<n;i++)
{
visited[i]=0;
dist[i]=cost[src][i];
}
visited[src]=1;
dist[src]=0;
for(i=0;i<n;i++)
{
if(i==src) continue;
min=999;
for(j=0;j<n;j++)
if((visited[j]==0)&&(min>dist[j]))
{
min=dist[j];
u=j;
}
visited[u]=1;
for(j=0;j<n;j++)
if(visited[j]==0)
{
if(dist[j]>dist[u]+cost[u][j])
dist[j]=dist[u]+cost[u][j];
}
}
}
public static void main(String[] args)
{
Scanner sc=new Scanner(System.in);
System.out.println("Enter the number of vertices");
n=sc.nextInt();
System.out.println("Enter the matrix");
cost=new int[n][n];
dist=new int[n];
Arrays.fill(dist,0);
for(i=0;i<n;i++)
for(j=0;j<n;j++)
cost[i][j]=sc.nextInt();
System.out.println("Enter the source vertex");
src=sc.nextInt();
new Dijkstra().dij(src, cost, dist, n);
System.out.println("Shortest path from "+src+" to all other vertices");
for(i=0;i<n;i++)
System.out.println("To " +i+" is "+dist[i]);
}
}
