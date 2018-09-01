#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <sys/time.h>
#include <stdlib.h>
#include <algorithm>

class SeqContain {
 public:
  template <typename T_CON>
  int TestSeq(const int N) {
    T_CON v_con;
    struct timeval start_tv;
    gettimeofday(&start_tv, NULL);
    for (int i = 0; i < N; ++i) {
        v_con.push_back(i);
    }
    struct timeval end_tv;
    gettimeofday(&end_tv, NULL);
    std::cout << "插入：" << end_tv.tv_sec - start_tv.tv_sec <<"s " <<  abs(end_tv.tv_usec - start_tv.tv_usec) << "microsecond" << std::endl;

    gettimeofday(&start_tv, NULL);
    typename T_CON::iterator it = find(v_con.begin(), v_con.end(), N/2);
    gettimeofday(&end_tv, NULL);
    std::cout << "查找:" << end_tv.tv_sec - start_tv.tv_sec <<"s " <<  abs(end_tv.tv_usec - start_tv.tv_usec) << "microsecond" << std::endl;

    gettimeofday(&start_tv, NULL);
    v_con.erase(it);
    gettimeofday(&end_tv, NULL);
    std::cout << "删除:" << end_tv.tv_sec - start_tv.tv_sec <<"s " <<  abs(end_tv.tv_usec - start_tv.tv_usec) << "microsecond" << std::endl;
    return 1;
  }
};

int main(int argc, char**argv) {
    if (argc != 3) {
        std::cout << "./sq 容器类型 操作次数" << std::endl;
        return 1;
    }

    std::string con_type(argv[1]);
    int n = atoi(argv[2]);
    
    if (con_type != "vector" || cont_type != "deque" || con_type != "list") {
      std::cout << "请输入vector,deque,list容器中一种" << std::endl;
      return 1;
    }

    std::cout << "你输入的容器类型是:" << con_type << ",操作次数是:" << n << std::endl;

    SeqContain seq_con_test;

    if (con_type == "vector") {
      seq_con_test.TestSeq<std::vector<int> >(n);
    } else if (con_type == "deque") {
      seq_con_test.TestSeq<std::deque<int> >(n);
    } else if (con_type == "list") {
      seq_con_test.TestSeq<std::list<int> >(n);
    }
    return 0;
}
