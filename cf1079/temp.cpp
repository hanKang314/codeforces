
                for (int i = 0; i < n; i++) {
                    if (i == 0) {
                        if (a[0] == temp1[0] || a[0] == temp1[1]) {
                            temp2[0] = a[0];
                        }
                    } else if (i == n-1) {
                        if (a[n-1] == temp1[n-1] || a[n-1] == temp1[n-2]) {
                            temp2[n-1] = a[n-1];
                        }
                    } else {
                        if (a[i] == temp1[i] || a[i] == temp1[i-1] || a[i] == temp1[i+1]) {
                            temp2[i] = a[i];
                        }
                    }
                }