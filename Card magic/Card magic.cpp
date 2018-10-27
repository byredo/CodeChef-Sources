#include <fstream>

using namespace std;

ifstream fin("q.in");
ofstream fout("qq.out");

const int DM = 1e5 + 1;

int t,n;
int pack[DM];
pair < int, int > maxim, minim;

int main()
{
    fin >> t;
    for(int i = 1; i <= t; i++)
    {
        fin >> n;
        
        maxim.first = 0;
        minim.first = 1e6 + 2;
        
        for(int j = 1; j <= n; j++)
        {
            fin >> pack[j];
            
            if(pack[j] > maxim.first)
            {
                maxim.first = pack[j];
                maxim.second = j;
            }
            
            if(pack[j] < minim.first)
            {
                minim.first = pack[j];
                minim.second = j;
            }
        }
        
        
        bool sortat = true;
        for(int j = 2; j <= n; j++)
            if(pack[j] < pack[j - 1])
                sortat = false;
        
        if(sortat)
            fout << "YES\n";
        else
        {
            bool sortatmin = true, sortatmax = true;
            
            for(int j = 1; j < maxim.second; j++)
                if(pack[j] > pack[j + 1])
                    sortatmax = false;
            
            for(int j = minim.second; j < n; j++)
                if(pack[j] > pack[j + 1])
                    sortatmin = false;
            
            if(sortatmax && sortatmin && minim.second == maxim.second + 1)
                fout << "YES\n";
            else
                fout << "NO\n";
        }
    }
    
}
