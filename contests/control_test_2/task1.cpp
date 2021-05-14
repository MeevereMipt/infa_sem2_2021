//
// Created by Meevere on 5/14/2021.
//

#include <iostream>

namespace control2 {

    int task1(){
        int N;
        std::cin >> N;

        long *h, *k;
        h = new long [N];
        k = new long [N];

        bool flag = false;

        for(int i=0; i<N; i++){
            std::cin >> h[i] >> k[i];
            if(!flag){
                for(int j=i-1; j>=0; j--){
                    for( int l=j-1; l>=0; l--) {
                        if (h[i] > h[j] and h[i] > h[l]) {
                            flag = (h[i] == (h[j] + h[l])) and (k[i] == (k[j] + k[l]));
                        } else if (h[j] > h[i] and h[j] > h[l]) {
                            flag = (h[j] == (h[i] + h[l])) and (k[j] == (k[i] + k[l]));
                        }else {
                            flag = (h[l] == (h[i] + h[j])) and (k[l] == (k[i] + k[j]));
                        }
                        if (flag) goto LOOP_EXIT; // break out of nested loops
                    }
                }
                LOOP_EXIT:;
            }
        }

        std::cout << (flag ? "YES" : "NO");

        delete [] h;
        delete [] k;
        return 0;
    }
}