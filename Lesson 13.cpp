// Задание 1

#include <fstream>
#include <stack>
#include <vector>
#include <iostream>
#include <clocale>
#include <iostream>
#include <ctime>
#include <vector>
#include <queue>
#include <conio.h>

#define N 10
using namespace std;
 
void designing(int* , int, int, ofstream&); 
 
int main()
{
    setlocale(LC_ALL, "Russian");
    ofstream o("result.txt");
    ifstream in("A.txt");
    if (!in) return 1;
    stack <int> st;
    bool includedinstack[N]; 
    bool DUG[N][N]; 
    int start, end;
    int rang[N]; 
    int PointIndicator[N]; 


    cout<< "Вершина: ";
    do{ cin>> start;} while (start < 0 || start > 9);
    cout<< "Конечная : ";
    do{ cin>> end;} while (end < 0 || end > 9 || end == start);
    for (int i = 0; i < N; i++)
    {
        PointIndicator[i] = start;
        rang[i] = 999;
        includedinstack[i] = false;
        for (int j = 0; j < N; j++)
            in>> DUG[i][j];
    }
    
    st.push (start);
    includedinstack[start] = true;
    PointIndicator[start] = -1;
    rang[start] = 0;

    while (!st.empty())
    {
          int besuch = st.top();
          st.pop();
          for (int i = 0; i < N; i++)
          {
              if (!includedinstack[i] && DUG[besuch][i])
              {
                  st.push (i);
                  includedinstack[i] = true;
                  rang[i] = rang[besuch] + 1;
                  PointIndicator[i] = besuch;
              }
          }
    }
    designing(PointIndicator, rang[end], end, o);
    in.close();  o.close();
    return 0;
}
 
void designing(int *p, int rang, int end, ofstream &o)
{
    vector <int> v;
    vector <int>::iterator cur;
    for (int i = end; i != -1; i = p[i])
        v.push_back(i);
    o<< "Количество переходов: "<< rang<< endl;
    for (cur = v.end() - 1; cur >= v.begin(); cur--)
        o<< *cur<< " ";
}




// Задание 2
//а


using namespace std;
 
const int n=10000;
int i, j;
int GM[n][n];

 
bool *vis=new bool[n];
bool *visited=new bool[n];
 
vector < vector <int> > g(n);
vector <int> used(n); 

//сложность n^2
void BFS(bool *passed, int unit)
{
    int *posl=new int[n];

    int count, head;
    for (i=0; i<n; i++) posl[i]=0;
    count=0; head=0;
    posl[count++]=unit;
    passed[unit]=true;
    while (head<count)
    {
        unit=posl[head++];
        for (i=0; i<n; i++)
            if (GM[unit][i] && !passed[i])
            {
                posl[count++]=i;
                passed[i]=true;
            }
    }
    delete []posl;
}
void bfs2 (int s)
{
queue<int> q;
q.push (s);
vector<bool> used (n);
used[s] = true;
while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (vector<int>::iterator i=g[v].begin(); i!=g[v].end(); ++i)
        if (!used[*i-1])
        {
            used[*i-1]=true;
            q.push(*i-1);
        }
}
}
//сложность n^2
void DFS(int st)
{
    int r;
    visited[st]=true;
    for (r=0; r<=n; r++)
        if ((GM[st][r]!=0) && (!visited[r]))
    DFS(r);
}
//сложность n+m
void dfs2 (int v) {
    used[v] = true;
    for (vector<int>::iterator i=g[v].begin(); i!=g[v].end(); ++i)
        if (!used[*i-1])
        {
            dfs2 (*i-1);
            
        }
    
}
 
void main()
{
    srand (time(NULL));
    setlocale(LC_ALL, "Rus");
    int start;
    cout<<"Вершина >> "; cin>>start;
    cout<<"Матрица смежности: "<<endl;
 
    for (i=0;i<n;i++)
        for (j=i;j<n;j++)
        {
            GM[i][j]=rand() % 2;
            GM[j][i]=GM[i][j];
        }
    for (i=0;i<n;i++)
        GM[i][i]=0;
    int l,k;
    l=k=0;
    for (i=0; i<n; i++)
    {
        used[i]=0;
        visited[i]=false;
        vis[i]=false;
        for (j=0; j<n; j++)
        {
            
        }
        cout<<endl;
    }
    for(i = 0; i < n; ++i)
    {
        for (j=0;j<n;j++)
            if (GM[i][j]==1) k++;
        g[i].resize(k);
        for (j=0;j<n;j++)
            if (GM[i][j]==1)
            {
                g[i][l] = j+1;
                l++;
            }
     l=0;k=0;
    }

    for (i=0; i<n; i++)
    {
        for (j=0; j<(int)g[i].size(); j++)
        {
            
        }
    }
 
    unsigned int start_time =  clock();
    BFS(vis, start-1);
    unsigned int end_time = clock();
    cout << "runtime N^2 = " << (end_time-start_time)/1000.0 <<" N="<<n<< endl;
    cout<<endl;
 
    start_time =  clock();
    bfs2(start-1);
    end_time =  clock();
    cout << "runtime N^2 = " << (end_time-start_time)/1000.0 <<" N="<<n<< endl;
    cout<<endl;
 
    start_time =  clock();
    DFS(start-1);
    end_time =  clock();
    cout << "runtime N^2 = " << (end_time-start_time)/1000.0 <<" N="<<n<< endl;
    cout<<endl;
 
    start_time =  clock();
    dfs2(start-1);
    end_time =  clock();
    cout << "runtime N^2 = " << (end_time-start_time)/1000.0 <<" N="<<n<< endl;
    delete []visited;
    delete []vis;
    system("pause>>void");
}

//б
задание 2 б

using namespace std;



const int nb = 8;

bool* visit = new bool[n];

int ochered[nb];

int v_Start = 0;

int head = 0, tail = 0;



int graph[n][n] =

{

{ 0, 1, 0, 0, 0, 0, 0, 0 },

{ 1, 0, 1, 1, 0, 0, 0, 0 },

{ 0, 1, 0, 0, 1, 1, 0, 0 },

{ 0, 1, 0, 0, 0, 0, 0, 1 },

{ 0, 0, 1, 0, 0, 0, 1, 0 },

{ 0, 0, 1, 0, 0, 0, 1, 0 },

{ 0, 0, 0, 0, 1, 1, 0, 1 },

{ 0, 0, 0, 1, 0, 0, 1, 0 }

};

void BFS(int v_Start)

{

    visit[v_Start] = 1;

    while (head <= tail)

    {

        int v_this = ochered[head];

        head++;

        for (int i = 0; i < n; i++)

        {

            if ((graph[v_this][i] != 0) && (visit[i] == false))

            {

                visit[i] = true;

                tail++;

                ochered[tail] = i;

            }

        }

    }

}

void main()

{

    setlocale(LC_ALL, "Rus");

    for (int i = 0; i < nb; i++)

    {

        visit[i] = 0;

        ochered[i] = 0;

    }
    for (int i = 0; i < nb; i++)

    {

        for (int j = 0; j < nb; j++)

            cout << " " << graph[i][j];

        cout << endl;

    }
    cout << "Стартовая вершина >> ";

    cin >> v_Start;



    v_Start = v_Start - 1;

    ochered[0] = v_Start;

    BFS(v_Start);

    int AntiC = 0;

    for (int i = 0; i < n; i++)

    {

        if (visit[i] == false)

        {

            tail++;

            ochered[tail] = i;

            BFS(i);

        }

    }
}
