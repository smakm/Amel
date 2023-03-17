#include <iostream>

using namespace std;

class din_arr{
private:
    int *p;
    int len;
public:
    din_arr(int N=0): p(0), len(0){
        set(N);
    }
    
    void set(int N){
        if (N>0) p = new int[N];
        if (p) len=N;
    }
    
    ~din_arr(){}
    
    din_arr(const din_arr & tmp): p(0), len(0){
        if(tmp.len > 0) p = new int[tmp.len];
        if(p)
        {
            len=tmp.len;
            for(int i=0;i<len;i++)
            {
                p[i]=tmp.p[i];
            }
        }
    }
    
    int operator[](int index){
        if(index<0 || index>len) throw ("Вы вышли за пределы массива");
        else return p[index];
    }
    
    int & operator[](int index) const{
        if(index<0 || index>len) throw ("Вы вышли за пределы массива\n");
        else return p[index];
    }
    
    void insert(int q){
        int *pn = new int[len+1];
        for(int i=0;i<len;i++)
            pn[i]=p[i];
        pn[len]=q;
        len++;
        delete []p;
        p=pn;
    }
    
    void erase(int q){
        int k=0;
        int *pn = new int[len-1];
        for(int i=0;i<len;i++)
        {
            if(i!=q)
            {
                pn[k]=p[i];
                k++;
            }
        }
        len--;
        delete []p;
        p=pn;
    }
    
    void swap()
    {
        int a;
        for(int i=0;i<((int)(len/2));i++)
        {
            a=p[i];
            p[i]=p[len-1-i];
            p[len-1-i]=a;
        }
    }
    
    
    friend ostream & operator<<(ostream& out,din_arr& tmp);
    friend istream & operator>>(istream& is,din_arr& tmp);
};

istream & operator>>(istream& is,din_arr& tmp){
    if(tmp.len==0) throw ("Error! Массив нулевой\n");
    for(int i=0;i<tmp.len;i++)
    {
        is>>tmp.p[i];
    }
    return is;
}

ostream & operator<<(ostream& out,din_arr& tmp){
    if(tmp.len==0) throw("Error! Массив нулевой\n");
    for(int i=0;i<tmp.len;i++)
    {
        out<<tmp.p[i]<<' ';
    }
    return out;
}

int main(){
    setlocale(LC_ALL,"rus");
    char op='o';
    int q;
    din_arr A;
    cout<<"Введите длинну массива: "<<flush;
    cin>>q;
    A.set(q);
    cout<<"Введите значения массива, длинной: "<<q<<endl<<flush;
    cin>>A;
    while(op!='0'){
        cout<<"\n Выберите команду:\n i : Вставить элемент в конец\n e : Удалить i-ий эелемент\n s : перевернуть масив\n 0 : Завершить\n"<<flush;
        cin>>op;
        switch(op)
        {
            case 'I':
            case 'i':{
                int q;
                cout<<"Введите число : "<<flush;
                cin>>q;
                A.insert(q);
                break;
            }
            case 'E':
            case 'e':{
                int i;
            again:
                cout<<"Введите i :"<<flush;
                cin>>i;
                if(i<0 || i>q)
                {
                    cout<<"Вы вышли за пределы массива!!!\nПовтрите ввод"<<endl<<flush;
                    goto again;
                }
                A.erase(i);
                break;}
            case 'S':
            case 's':{
                A.swap();
                break;
            }
            case '0' : {op='0';break;}
            default: {
                cout<<"Команда отсутсвует"<<endl<<flush;
                break;
            }
        }
        cout<<A<<endl<<flush;
    }
    return 0;
}

