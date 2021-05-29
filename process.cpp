#include<bits/stdc++.h>
using namespace std;
char a[105];
void stringtoarray(string s)
{
	memset(a,0,sizeof a);
	for(int i=0;i<s.size();i++)
		a[i]=s[i];
}
int main()
{
	freopen("size.txt","r",stdin);
	freopen("nul.txt","w",stdout);
	map<long long,vector<string> >mp;
	vector<vector<string> >ans;
	string s,t;
	long long x;
	getline(cin,s);
	while(1)
	{
		getline(cin,t);
		while(s[s.size()-1]==' ')
			s.erase(s.end()-1);
		if(s=="end")
			break;
		s.erase(s.end()-1);
		while(t[t.size()-1]==' ')
			t.erase(t.end()-1);
		x=0;
		for(int i=0;i<t.size();i++)
			x=x*10+t[i]-'0';
		mp[x].push_back(s);
		getline(cin,s);
	}
	for(map<long long,vector<string> >::iterator it=mp.begin();it!=mp.end();it++)
		if((it->second).size()>1)
		{
			vector<string>v=(it->second);
			bool f[105]={};
			for(int i=0;i<v.size();i++)
				if(!f[i])
				{
					vector<string>tmp;
					tmp.push_back(v[i]);
					for(int j=i+1;j<v.size();j++)
					{
						stringtoarray("fc "+v[i]+" "+v[j]);
						if(!system(a))
						{
							tmp.push_back(v[j]);
							f[j]=true;
						}
					}
					if(tmp.size()>1)
						ans.push_back(tmp);
				}
		}
	freopen("result.txt","w",stdout);
	if(ans.empty())
		puts("Not any same files.");
	else
	{
		puts("There are some same files: ");
		for(int i=0;i<ans.size();i++)
		{
			for(int j=0;j<ans[i].size();j++)
				cout<<ans[i][j]<<"     ";
			cout<<endl;
		}
	}
	return 0;
}
