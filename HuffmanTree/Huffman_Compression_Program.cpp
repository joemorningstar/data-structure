//
//  Huffman_Compression_Program.cpp
//  huffman
//
//  Created by 乔尔 on 2020/3/25.
//  Copyright © 2020 乔尔. All rights reserved.
//


#include "Assistance.hpp"
#include "HuffmanTree.hpp"
#include <vector>

std::vector<char> Cha;//字符串
std::vector<int> Freq;//

void menu();
void OpenFile();
void Encode();
void Decode(){};



int main()
{
    menu();
    return 0;
}

void menu()
{
    while(1)
    {
        char op;
        cout<<"-----"<<"蔡卓悦的哈夫曼压缩！"<<"-----"<<endl<<endl;
        cout<<"|    "<<"1.压缩文件"<<endl;
        cout<<"|    "<<"2.解压文件"<<endl;
        cout<<"|    "<<"Press Q to quit"<<endl;
        cout<<endl;
        cin>>op;
        if(op!='q' && op !='Q')
        {
           if(op=='1')
           {
               Encode();
           }
            else if(op=='2')
            {
                Decode();
            }
            else return;
        }
        else
            exit(0);
        
    }
 
}

void Encode(){
    
    int fre[300];
    for(int k=0;k<300;k++)
    {
        fre[k]=0;
    }
    string input;
    cout<<"Hello!"<<endl;
    cout<<"输入文件路径：";
    cin>>input;
    ifstream openFile;
    openFile.open(input.c_str(),ios::in);
    
    if(openFile.is_open()){
        cout<<"---------File Opened"<<endl;
    }
    else{
        cout<<"Error in opening file!!!"<<endl;
        return;
    }
     
    //read untill end of file is not found.
    char ch; //to read single character
    cout<<"File content: ";
    while(!openFile.eof())
    {
        openFile>>ch; //read single character from file
        cout<<ch;
        fre[(int)ch]+=1;
    }
    cout<<endl;
    openFile.close();
    
    
    for(int i=0;i<300;i++)
    {
        if(fre[i]){
            Cha.push_back((char)i);
            Freq.push_back(fre[i]);
        }
    }
    
    for(int i=0;i<Cha.size();i++)
    {
        cout<<Cha[i]<<"   "<<Freq[i]<<endl;
    }
    
    
    try    {                    // 用try封装可能出现异常的代码
        //char ch[] = {'A', 'B', 'C', 'D'};
        //int w[] = {12, 3, 5, 9};
        //int n = 4, i;
        unsigned long n=Freq.size();
        int i;
        char ch[n];
        int w[n];
        for(int i=0;i<n;i++)
        {
            ch[i]=Cha[i];
            w[i]=Freq[i];
        }
        HuffmanTree<char, int> hmTree1(ch, w,n);
        HuffmanTree<char, int> hmTree(hmTree1);
        hmTree = hmTree1;
        String strText ="helloworld!" ;    // 文本串

        cout << "各字符的编码为:" << endl;
        for (i = 0; i < n; i++)  {
            String strTmp = hmTree.Encode(Cha[i]);
            cout << Cha[i] << " : " << strTmp.CStr() << endl;
        }
        
        
        fstream comfile;
    comfile.open("/Users/IMAC/desktop/compressed.txt",ios::out);
        
        cout << "文本串" << strText.CStr() << "编码为:";
        for (i = 0; i < strText.GetLength(); i++)        {
            String strTmp = hmTree.Encode(strText[i]);
            //cout << strTmp.CStr();
            comfile<< strTmp.CStr();
        }
        comfile.close();
        cout << endl;
        system("PAUSE");
        string strCode="1100101100000111101011111100010101001";
        
        cout << "编码串" << strCode.CStr() << "译码为:";
            LinkList<char> lkText = hmTree.Decode(strCode);
            strText = lkText;
            cout << strText.CStr() << endl;
            
            
        }
        
    catch (Error err)    {    // 捕捉并处理异常
        err.Show();            // 显示异常信息
    }
    

    

}


  


