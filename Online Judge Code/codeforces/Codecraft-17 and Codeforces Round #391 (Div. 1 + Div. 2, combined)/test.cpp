#include<bits/stdc++.h>

using namespace std;

//extern FILE* logout;

const int TOTAL_BUCKET = 50;

class SymbolInfo
{
    string name;
    string type;
    vector<string>param;
    string funcRet;
    string dataType;
public:
    SymbolInfo()
    {
        name = "?";
        type = "?";
    }
    SymbolInfo( string name_, string type_ = "?", string dataType_ = "?", vector<string>param_ = vector<string>(), string funcRet_ = "?" )
    {
        name = name_;
        type = type_;
        param = param_;
        funcRet = funcRet_;
        dataType_ = dataType_;
    }
    void setParam( vector<string>vec )
    {
        param = vec;
    }
    void setName( string name_ )
    {
        name = name_;
    }
    void setType( string type_ )
    {
        type = type_;
    }
    void setFuncRet( string funcRet_ )
    {
        funcRet = funcRet_;
    }
    void setDataType( string dataType_ )
    {
        dataType = dataType_;
    }
    string getName()
    {
        return name;
    }
    string getType()
    {
        return type;
    }
    vector<string> getParam()
    {
        return param;
    }
    string getFuncRet()
    {
        return funcRet;
    }
    string getDataType()
    {
       return dataType;
    }
    friend ostream &operator<<( ostream &output, const SymbolInfo &data )
    {
        output << "<" << data.name << " : " << data.type << ">";
        return output;
    }

};

class ScopeTable
{
    vector<vector<SymbolInfo>> data;
    int bucket;
public:
    ScopeTable( int bucket_ = TOTAL_BUCKET)
    {
        bucket = bucket_;
        data.resize(bucket);
    }
    int Hash(const string &key)
    {
        int pr = 137;
        long long d = 0;
        for( int i = 0; i < key.length(); i++ )
        {
            d = d*pr + key[i];
            d %= bucket;
        }
        return d%bucket;
    }
    SymbolInfo* insert( string key, string val )
    {
        int ind = Hash(key);
        SymbolInfo* si = lookUp(key);
        if( si != 0 )
        {
            return si;
        }
        SymbolInfo *temp = new SymbolInfo( key, val );
        data[ind].push_back( *temp );
        return temp;
    }
    SymbolInfo* insert( SymbolInfo temp )
    {
        int ind = Hash(temp.getName());
        SymbolInfo* si = lookUp(temp.getName());
        if( si != 0 )
        {
            return si;
        }
        data[ind].push_back( temp );
        return &data[ind][ data[ind].size()-1 ];
    }
    SymbolInfo* lookUp( const string &key )
    {
        int cnt = 0;
        int ind = Hash(key);
        for( int i = 0; i < data[ind].size(); i++ )
        {
            if( data[ind][i].getName() == key )
            {
                return &data[ind][i];
            }
        }
        return 0;
    }
    bool remove( const string &key )
    {
        int ind = Hash(key), found = -1;
        for( int i = 0; i < data[ind].size(); i++)
        {
            if( data[ind][i].getName() == key )
            {
                found = i;
                break;
            }
        }
        if( found == -1 ) return false;
        data[ind].erase( data[ind].begin() + found );
        return true;
    }

    void print( int ind )
    {
        if( data[ind].size() == 0 ) return;
        cout << ind << "--> ";
        for( int i = 0; i < data[ind].size(); i++ )
        {
            cout << data[ind][i] << " ";
        }
        cout << endl;
    }
    void print( int ind, FILE *file )
    {
        if( data[ind].size() == 0 ) return;
        fprintf(file, "%d-->", ind);
        for( int i = 0; i < data[ind].size(); i++ )
        {
            fprintf(file, "<%s : %s> ", data[ind][i].getName().c_str(), data[ind][i].getType().c_str());
        }
        fprintf(file, "\n");
    }
    void print()
    {
        for( int i = 0; i < bucket; i++ )
            print(i);
    }
    void print(FILE *file)
    {
        for( int i = 0; i < bucket; i++ )
            print(i, file);
    }
};

class SymbolTable
{
    int curscope, scopeCount;
    vector<ScopeTable>scopes;
    vector<int>scopeID;
public:
    SymbolTable()
    {
        cout << "symbol table" << endl;
        curscope = -1;
        scopeCount = 0;
    }
    int getCurrentScope()
    {
        return curscope;
    }
    void enterScope(int bucket = TOTAL_BUCKET)
    {

        scopes.push_back( *(new ScopeTable(bucket)) );
        scopeID.push_back(scopeCount++);
        curscope = scopes.size()-1;
    }
    void enterScope( FILE* file, int bucket = TOTAL_BUCKET)
    {

        scopes.push_back( *(new ScopeTable(bucket)) );
        scopeID.push_back(scopeCount++);
        curscope = scopes.size()-1;
        fprintf(file, "\t\tEntered Scope #%d\n\n", scopeCount-1);
    }
    void exitScope()
    {
        if( scopes.size() > 0 )
        {
            int temp = scopeID[curscope];
            cout << "Exited Scope #" << temp << endl;
            printCurrentScopeTable();
            scopes.pop_back();
            scopeID.pop_back();
            curscope = scopes.size()-1;
        }
        else
        {
            cout << "Sorry, no scope currently" << endl;
        }
    }
    void exitScope(FILE *file )
    {
        if( scopes.size() > 0 )
        {
            int temp = scopeID[curscope];
            fprintf(file, "\t\tExited Scope #%d\n\n", temp);
            printAllScopeTable(file);
            scopes.pop_back();
            scopeID.pop_back();
            curscope = scopes.size()-1;
        }
        else
        {
            fprintf(file, "Sorry, no scope currently\n");
        }
    }
    SymbolInfo* insert(string key, string val)
    {
        if( curscope < 0 ) return 0;
        return scopes[curscope].insert( key, val);
    }
    SymbolInfo* insert(SymbolInfo temp)
    {
        if( curscope < 0 ) return 0;
        return scopes[curscope].insert( temp );
    }
    bool remove(const string &key)
    {
        if( curscope < 0 ) return false;
        return scopes[curscope].remove(key);
    }
    bool doesExist( const string &key_, const string &type_ )
    {
        int f = 0;
        for( int i = curscope; i >= 0; i-- )
        {
            SymbolInfo* si = scopes[i].lookUp(key_);
            if( si != 0 && si->getType() == type_ )
                f++;
        }
        return f>0;
    }
    SymbolInfo* lookUpAll(const string &key)
    {
        if( curscope < 0 ) return 0;
        for( int i = curscope; i >= 0; i-- )
        {
            SymbolInfo* si = scopes[i].lookUp(key);
            if( si != 0 )
                return si;
        }
    }
    SymbolInfo* lookUp(const string &key)
    {
        if( curscope < 0 ) return 0;
        return scopes[curscope].lookUp(key);
    }
    void printCurrentScopeTable()
    {
        if( curscope < 0 ) return ;
        scopes[curscope].print();
    }
    void printAllScopeTable()
    {
        cout << "\t\tSymbol Table Fullprint:" << endl;
        for( int i = 0; i < scopes.size(); i++ )
        {
            cout << "Symbol Table #" << scopeID[i] << endl;
            scopes[i].print();
            cout << endl;
        }
    }
    void printAllScopeTable(FILE *file)
    {
        fprintf(file, "\t\tSymbol Table Fullprint:\n");
        for( int i = 0; i < scopes.size(); i++ )
        {
            fprintf(file, "\t\tSymbol Table #%d:\n", scopeID[i]);
            scopes[i].print(file);
            fprintf(file, "\n");
        }
        fprintf(file, "\n");
    }
};
/*
int main()
{
    //constructor test SymbolInfo
    SymbolInfo s1( "ID", "10" ), s2("keyword", "INT");

    //Print test SymbolInfo
    cout << s1 << endl;
    cout << s2 << endl;

    //setter test SymbolInfo
    s1.setName("id");
    cout << s1 << endl;

    //getter test SymbolInfo
    cout << s1.getType() << endl;
    cout << endl << endl;


    //initialization test Scope Table
    ScopeTable st(5);

    //insert test Scope Table
    cout << st.insert("ID", "10") << endl;
    cout << st.insert("tanveer", "ok") << endl;
    cout << st.insert("keyword", "INT") << endl;
    cout << st.insert("constant", "100") << endl;
    cout << st.insert("hello", "world") << endl;
    cout << st.insert("new", "table") << endl;
    cout << st.insert("do", "while") << endl;

    //print test ScopeTable
    st.print();
    cout << endl ;

    //remove test Scopetable
    st.remove("tanveer");
    st.remove("ok");
    st.remove("hello");
    st.remove("do");
    st.print();


    return 0;
}*/
/*
int main()
{
    //freopen("input.txt", "r", stdin);
    int buc;
    char ch;
    cin >> buc;
    SymbolTable st;
    st.enterScope(buc);

    while( cin >> ch )
    {
        if( ch == 'I' )
        {
            string a, b;
            cin >> a >> b;
            SymbolInfo* flag = st.lookUp(a);
            if(flag == 0)
            {
                st.insert(a,b);
                cout << "Inserted" << endl;
            }
            else
                cout << "already exist" << endl;
        }
        else if( ch == 'L' )
        {
            string a;
            cin >> a;
            SymbolInfo* sm = st.lookUp(a);
            if( sm == 0 )
                cout << "Not found" << endl;
            else
                cout << "found: " << (*sm) << endl;
        }
        else if( ch == 'D' )
        {
            string s;
            cin >> s;
            int flag = st.remove(s);
            if(flag)
            {
                cout << "Deleted" << endl;
            }
            else
                cout << "doesn't exist" << endl;
        }
        else if( ch == 'P' )
        {
            char c;
            cin >> c;
            if( c == 'C' )
                st.printCurrentScopeTable();
            else
                st.printAllScopeTable();
        }
        else if( ch == 'S' )
        {
            st.enterScope(buc);
        }
        else if( ch == 'E' )
        {
            st.exitScope();
        }
    }

    return 0;
}
*/
