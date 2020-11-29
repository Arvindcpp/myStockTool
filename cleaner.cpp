#include<bits/stdc++.h>
#include<fstream>
using namespace std;
typedef unordered_set<string> usetstr;

void getValue(string compName, string attr, int nextNLines)
{
	string first = string("grep ") + "-A" + to_string(nextNLines) + " \"" + string(attr) + "\" ";
	string third = " >> " + compName + "save";
	first = first + compName + third;
	const char *str = first.c_str();
	system(str);
}

void saveDataOf(string companyName)
{
	getValue(companyName, "closePrice", 0);
	getValue(companyName, "TodayHigh", 0);
	getValue(companyName, "TodayLow", 0);
	getValue(companyName, "52WH", 0);
	getValue(companyName, "52WL", 0);
	getValue(companyName, "52WL", 0);
	getValue(companyName, "<h6>Ownership", 1);
	getValue(companyName, "<h6>Valuation", 0);
	getValue(companyName, "<h6>Efficiency", 0);
	getValue(companyName, "<h6>Financials", 0);
	getValue(companyName, "<small>Market Cap", 2);
	getValue(companyName, "EntValue", 0);
	getValue(companyName, "No. of Shares", 2);
	getValue(companyName, "<small>P/E", 2);
	getValue(companyName, "<small>P/B", 2);
	getValue(companyName, "<small>Face Value", 2);
	getValue(companyName, "Div. Yield", 2);
	getValue(companyName, "Book Value (TTM)", 3);
	getValue(companyName, "ltrlCash", 0);
	getValue(companyName, "ltrlDebt", 0);
	getValue(companyName, "<small>Promoter Holding", 2);
	getValue(companyName, "EPS (TTM)", 3);
	getValue(companyName, "Sales Growth</span>", 4);
	getValue(companyName, "<small>ROE", 3);
	getValue(companyName, "<small>ROCE", 3);
	getValue(companyName, "<small>ROE", 3);
	getValue(companyName, "<small>Profit Growth", 3);
	getValue(companyName, "Pledge", 32);
	getValue(companyName, "mainContent_hfSizeForQuarter", 50);
	getValue(companyName, "Profit & Loss", 290);
	getValue(companyName, "Balance Sheet<small>", 417);
	getValue(companyName, "Cash Flows<small>", 146);
}

void siteDownloader(usetstr &tisset)
{
	for(auto &a: tisset){
		system(("wget " + string("https://ticker.finology.in/company/" + a)).c_str());
	}
}
int main()
{
	usetstr uset= {"RELIANCE", "TCS", "ITC", "HINDUNILVR", "COALINDIA", "WIPRO", "SUNPHARMA", "TATAMOTORS", "HCLTECH", "ASIANPAINT", "BPCL"};
	siteDownloader(uset);
	for(auto a: uset){
		saveDataOf(a);
	}
}
