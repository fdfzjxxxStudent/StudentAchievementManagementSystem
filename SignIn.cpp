#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h> 
using namespace std;
int main(){
		string o;
		ofstream fout;
		fout.open("C:\\ProgramData\\StudentAchievementManagementSystem\\Welcome.txt");
		fout<<"��ӭʹ��ѧ���ɼ�����ϵͳ������һ�������ļ�������ɾ�� C:\\ProgramData\\StudentAchievementManagementSystem\\ ��һ��ɾ����ϵͳ��������"<<endl; 
		fout.close();
		system("mkdir C:\\ProgramData\\StudentAchievementManagementSystem");
		system("cmd.exe /c attrib C:\\ProgramData\\StudentAchievementManagementSystem\\ +h");
		system("title ѧ���ɼ�����ϵͳ");
		system("cls");
		cout<<"����δע�ᣬ�������û�����";
		cin>>o;
		fout.open("C:\\ProgramData\\StudentAchievementManagementSystem\\~Control.usr");
		if(!fout){
			MessageBox(NULL,"ϵͳ����\r\n���Թ���Ա����������г���","ѧ���ɼ�����ϵͳ",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
			exit(0);
		}
		fout<<o<<endl;
		fout.close();
		cout<<"���������룺";
		cin>>o;
		//�����㷨��ASCII���123
		for(long long i=0;i<=o.size();i++)
			o[i]=o[i]+123;
		fout.open("C:\\ProgramData\\StudentAchievementManagementSystem\\~Control.passwd");
		if(!fout){
			MessageBox(NULL,"ϵͳ����\r\n���Թ���Ա����������г���","ѧ���ɼ�����ϵͳ",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
			exit(0);
		}
		fout<<o<<endl;
		fout.close();
		system("cmd.exe /c attrib C:\\ProgramData\\StudentAchievementManagementSystem\\~Control.info +h");
		system("cmd.exe /c attrib C:\\ProgramData\\StudentAchievementManagementSystem\\~Control.passwd +h");
		system("mkdir %USERPROFILE\\AppData\\Local\\SAMS");
		fout.open("%USERPROFILE\\AppData\\Local\\SAMS\\~Reg");
		fout<<1<<endl;
		fout.close();
		system("cls");
		MessageBox(NULL,"ע��ɹ���","ѧ���ɼ�����ϵͳ",MB_ICONINFORMATION|MB_SYSTEMMODAL|MB_SETFOREGROUND); 
		return 0;
}
