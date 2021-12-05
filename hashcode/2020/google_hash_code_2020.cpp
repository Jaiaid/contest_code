#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define MAXLIB 100000
#define MAXBOOK 100000
#define INT_MAX (~(1<<31))

struct library{
	int id;
	int n;
	int sign_up_time;
	int par_scan_per_day;
	int work_day;
	float iou;
	float avg_profit;
	
	bool operator<(const library & obj)const
	{
		if (this->avg_profit == obj.avg_profit) {
			return this->work_day < obj.work_day;
		}
		return this->avg_profit > obj.avg_profit;
	}
};


std::map<int, int> global_book_count;

bool custom_comparison_func(int & i, int & j)
{
	return global_book_count[i] < global_book_count[j];
}

int main()
{
	int bcount, lcount, day;
	std::vector<library> lib_info;
	std::vector<int> book_score(MAXBOOK);
	std::vector<std::vector<int> > lib_book_list;
	
	unsigned int lib_to_sign_up;
	
	// read input and fill up book keeping data
	std::cin >> bcount >> lcount >> day;
	for(int i = 0;i < bcount;i++)
	{
		std::cin >> book_score[bcount];
	}
	 
	for(int i = 0;i < lcount;i++)
	{
		int tmp_n, tmp_st;
		std::cin >> tmp_n >> tmp_st;
		
		if (tmp_st >= day) {
			int tmp;
			std::cin >> tmp; 
			for(int j = 0;j < lib_info[i].n;j++)
			{
				std::cin >> tmp;
			}
		}
		else {
			int lib_holding_score = 0;
			
			lib_info.push_back(library());
			lib_book_list.push_back(std::vector<int>(tmp_n));
			
			lib_info.back().id = i;
			lib_info.back().n = tmp_n;
			lib_info.back().sign_up_time = tmp_st;
			std::cin >> lib_info.back().par_scan_per_day;
			lib_info.back().work_day = lib_info.back().sign_up_time + lib_info.back().n / lib_info.back().par_scan_per_day;
			
			for(int j = 0;j < lib_info[i].n;j++)
			{
				int b_id;
				std::cin >> b_id;
				lib_holding_score += book_score[b_id];
				lib_book_list[i][j] = b_id; 
				
				if (global_book_count.find(b_id) == global_book_count.end()) {
					global_book_count[b_id] = 1;
				}
				else {
					global_book_count[b_id]++;
				}
			}
			
			lib_info.back().avg_profit = (1.0 * lib_holding_score) / lib_info.back().work_day;
		}
	}
	// reading input and keeping relevent one
	
	// apply heuristic
	std::sort(lib_info.begin(), lib_info.end());
	// count how many library at most registered
	int tmp_day_count = 0;
	for (lib_to_sign_up = 0;
		lib_to_sign_up < lib_info.size() && tmp_day_count < day;
		lib_to_sign_up++)
	{
		tmp_day_count += lib_info[lib_to_sign_up].sign_up_time;
	}
	// heuristic done
	
	// output
	std::cout << lib_to_sign_up << std::endl;
	
	int sign_up_finishing_day = lib_info[0].sign_up_time;
	for (unsigned int i = 0;i < lib_to_sign_up;i++, sign_up_finishing_day += lib_info[i].sign_up_time)
	{
		std::vector<int> book_to_scan_list;
		book_to_scan_list.clear();
		
		int finishing_day = sign_up_finishing_day;
		std::sort(lib_book_list[lib_info[i].id].begin(), lib_book_list[lib_info[i].id].end(), custom_comparison_func);
		for (int j = 0;j < lib_info[i].n && finishing_day <= day;j++)
		{
			if (global_book_count[lib_book_list[lib_info[i].id][j]] != INT_MAX) {
				global_book_count[
					lib_book_list[lib_info[i].id][j]
				] = INT_MAX;
				book_to_scan_list.push_back(
					lib_book_list[lib_info[i].id][j]
				);
			}
			finishing_day = sign_up_finishing_day + book_to_scan_list.size() / lib_info[i].par_scan_per_day;
		}
		if (book_to_scan_list.size() == 0) {
			book_to_scan_list.push_back(
				lib_book_list[lib_info[i].id][0]
			);
		}
		
		
		if (i > 0) {
			std::cout << std::endl;
		}
		std::cout << lib_info[i].id << ' ' << book_to_scan_list.size() << std::endl;
		for (unsigned int j = 0;j < book_to_scan_list.size();j++)
		{
			std::cout << book_to_scan_list[j] << ' ';
		}
	}
	
	return 0;
}
