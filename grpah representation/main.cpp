//
//  main.cpp
//  grpah representation
//
//  Created by ayush_sharma on 13/10/20.
//  Copyright © 2020 ayush sharma. All rights reserved.
//

#include <iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

class graph{
public:
    
    int edges=0;
    int vertices=0;
    int **r;
    
public:
    graph(int edges,int vertices):edges(edges),vertices(vertices){
        r=new int*[vertices];
        for(int i=0;i<vertices;++i){
            r[i]=new int[vertices];
            for(int j=0;j<vertices;++j){
                r[i][j]=0;
        }
        }
    }
    graph(){}
    
    void getgraph(){
        cout<<"enter values for edges and vertices"<<endl;
        cin>>edges>>vertices;
        r=new int*[vertices];
        for(int i=0;i<vertices;++i){
            r[i]=new int[vertices];
            for(int j=0;j<vertices;++j){
                r[i][j]=0;
        }
        }
        
        for(int i=0;i<edges;++i){
            int l,c;
            cout<<"enter from to (end-points of edge (ordered))"<<endl;
            cin>>l>>c;
            cout<<"enter the cost for this edge"<<endl;
            int cost=0;
            cin>>cost;
            r[l][c]=cost;
//            r[c][l]=1;
        }
        
        
    }
    
    void formgraph(){
        cout<<"enter values for edges and vertices"<<endl;
        cin>>edges>>vertices;
        r=new int*[vertices];
        for(int i=0;i<vertices;++i){
            r[i]=new int[vertices];
            for(int j=0;j<vertices;++j){
                r[i][j]=0;
        }
        }
    }
    
    void add_edge(int x,int y,int data=1){
        r[x][y]=data;
//        r[y][x]=data;
    }
    
    void showgraph(){
        cout<<endl;
        int v=vertices;

        int ch=1;
//        char ch='A';
        if(v){
            cout<<"    ";
            while(v--)
                cout<<ch++<<" ";
            cout<<endl<<endl;
        }
            ch=1;
        for(int i=0;i<vertices;i++){
            cout<<ch++<<"   ";
            for(int j=0;j<vertices;++j){
                cout<<r[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    
    bool havepath_dfs(int a,int b){
        if(a<0 && b<0 && a>=vertices && b>=vertices)
            return false;
        else if(r[a][b]!=0)
            return true;
        
        for(int i=0;i<vertices;++i){
            if(r[a][i]!=0){
                if(havepath_dfs(i,b))
                    return true;
            }
        }
        
        return false;

        }
    bool havepath_bfs(int a,int b){
        if(a==b)
            return true;
        
        bool v[10]={false};
        
        queue<int> q;
        q.push(a);
        v[a]=true;

        
        while(!q.empty()){
            int x=q.front();
            q.pop();
            
            for(int i=0;i<vertices;++i){
                if(i==b && r[x][i]!=0)
                    return true;
                else if(!v[i] && r[x][i]!=0){
                    q.push(i);
                    v[i]=true;
                }
            }
        }

        return false;
        
    }
    void dfs(int i,bool v[]){
        if(!v[i]){
            v[i]=true;
            cout<<i+1<<" ";
        
        
        for (int j=0;j<vertices;++j){
            
            if(!v[j] && r[i][j]!=0){
                dfs(j,v);
            }
            
        }
        
        }
        
    }
    void bfs(int i){
        bool v[10]={false};
        queue<int> q;
        
        q.push(i);
        
        while(!q.empty()){
            int x=q.front();
            q.pop();
            
            if(!v[x]){
                cout<<x+1<<" ";
                v[x]=true;
            }
            
            for(int j=0;j<vertices;++j){
                if(!v[j] && r[x][j]!=0){
                    q.push(j);
                }
            }
        }
    }
    void dfs(int i){
        bool v[10]={false};
        stack<int> stack;
        stack.push(i);
        
        while(!stack.empty()){
            
            int x=stack.top();
            stack.pop();
            
            if(!v[x]){
                cout<<x+1<<" ";
                v[x]=true;
            }
            
            for(int j=0;j<vertices;++j){
            if(!v[j] && r[x][j]!=0){
                stack.push(j);
            }
            
        }
        
        
        }
        
    }
    void printedges(){
        //not correct yet
        for(int i=0;i<vertices;++i){
            for(int j=0;j<vertices;++j){
                if(havepath_dfs(i,j)){
                    cout<<"edge from "<<i+1<<"to "<<j+1<<endl;
                }
            }
        }
            
    }
    void travelsalesman(int a,int b){
        
        
        
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    graph g(5,6);
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(2,3);
    g.add_edge(3,5);
    g.add_edge(5,4);
    g.add_edge(1,4);
//    g.getgraph();
    g.showgraph();
//    bool v[10]={false};
//    g.dfs(0,v);
//    cout<<endl;
//    g.dfs(0);
//    cout<<endl;
//    g.bfs(0);
//    cout<<endl;
//    g.printedges();
    cout<<std::boolalpha<<g.havepath_dfs(0,5)<<endl;
    cout<<std::boolalpha<<g.havepath_dfs(2,1)<<endl;
    
    cout<<std::boolalpha<<g.havepath_bfs(0,4)<<endl;
    cout<<std::boolalpha<<g.havepath_bfs(4,0)<<endl;
    
    return 0;
}
