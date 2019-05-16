#include <iostream>
#include <map>
using namespace std;
int a, i, j, k, x, y, m[36001];
long long ans, t;
string s;
int main()
{
	cin>>a>>s;
	for (i=0;i<s.size();i++) {
		for (k=0,j=i; j<s.size(); j++) {
			k+=s[j]-'0';
			m[k]++;
		}
	}
	cout << m[0] << endl;
	if (a==0) {
		t = s.size()*(s.size()+1)/2;
		ans = t*t-(t-m[0])*(t-m[0]);
	}
	else for (k=1;k<=s.size()*9;k++) {
		if (k>0 && a%k==0 && a/k<=s.size()*9) {
			x = m[a/k];
			if (x>0) ans+=(long long)m[k]*x;
		}
	}
	cout<<ans<<endl;
	return 0;
}
