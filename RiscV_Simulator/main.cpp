#include <bits/stdc++.h> 
using namespace std;

struct tokens
{
    string name;
    string type;
    unsigned long opcode;
    unsigned long func3;
    unsigned long func7;
};


int create_refrence_table(struct tokens refrence_table[], map<string, int> &name_map, map<int, int> &opcode_map)
{
    ifstream fin;
    string nam,tp;
    int c,d,e,i=0;

    fin.open("reference_sheet.txt");
    while(fin>>nam>>tp>>c>>d>>e)
    {    
        string f = to_string(c);
        string g = to_string(d);
        string h = to_string(e);

        refrence_table[i].name = nam;
        refrence_table[i].type = tp;

        bitset<7> opcd(f);
        refrence_table[i].opcode = opcd.to_ulong();
        if(d!=-1)
        {
            bitset<3> fn3(g);
            refrence_table[i].func3 = fn3.to_ulong();
        }    
        
        if(e!=-1)
        {
            bitset<7> fn7(h);
            refrence_table[i].func7 = fn7.to_ulong();
        }    
        
        name_map.insert(pair<string,int>(nam, i));
        opcode_map.insert(pair<int,int>(opcd.to_ulong(), i));

        i++;
    }
    fin.close();
    return i;
}


void print_table(struct tokens refrence_table[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<refrence_table[i].name<<" \t"<<refrence_table[i].type<<" \t";
        cout<<refrence_table[i].opcode<<" \t"<<refrence_table[i].func3<<" \t"<<refrence_table[i].func7<<endl;
    }
}

int main()
{
    struct tokens refrence_table[100];    
    map<string, int> name_map;
    map<int, int> opcode_map;        //not required. Just leave it as it is.


    int refrence_table_size = create_refrence_table(refrence_table, name_map, opcode_map);
    print_table(refrence_table, refrence_table_size);

    string inst_name = "jal";            //Search any instruction's information by name;
    cout<<endl<<endl<<refrence_table[name_map.find(inst_name)->second].name<<"  \t"<<refrence_table[name_map.find(inst_name)->second].type<<"\t";
    cout<<refrence_table[name_map.find(inst_name)->second].opcode<<"\t"<<refrence_table[name_map.find(inst_name)->second].func3<<"\t";
    bitset<7> Bits(refrence_table[name_map.find(inst_name)->second].func7);
    cout<<Bits<<endl;
}


