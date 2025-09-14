#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
ll P;
const ll MOD = 500; // 只计算最后500位
ll digits[MOD];
//不开ll见祖宗
void multiply(ll a[], ll b[], ll res[]) {
    ll temp[MOD] = { 0 }; // 只保留低MOD位
    for (ll i = 0; i < MOD; i++) {
        if (a[i] == 0) continue;
        ll carry = 0;
        for (ll j = 0; j < MOD - i; j++) { // 确保不越界
            temp[i + j] += a[i] * b[j] + carry;
            carry = temp[i + j] / 10;
            temp[i + j] %= 10;
        }
        // 如果有剩余carry，忽略，因为我们只关心低MOD位
    }
    memcpy(res, temp, sizeof(temp));
}

void fastPower(ll e) {
    memset(digits, 0, sizeof(digits));
    digits[0] = 1; // 2^0 = 1
    ll base[MOD] = { 0 };
    base[0] = 2; // 初始值2
    while (e > 0) {
        if (e % 2 == 1) {
            ll temp[MOD] = { 0 };
            memcpy(temp, digits, sizeof(temp));
            multiply(temp, base, digits);
        }
        ll btemp[MOD] = { 0 };
        memcpy(btemp, base, sizeof(btemp));
        multiply(btemp, btemp, base);
        e /= 2;
    }
}

int main() {
    scanf("%lld", &P);
    ll total_digits = floor(P * log10(2.0) + 1); // 总位数
    printf("%lld\n", total_digits);

    fastPower(P); // 计算 2^P mod 10^MOD

    // 减1，处理借位
    ll borrow = 1;
    for (ll j = 0; j < MOD && borrow; j++) {
        if (digits[j] >= borrow) {
            digits[j] -= borrow;
            borrow = 0;
        }
        else {
            digits[j] = digits[j] + 10 - borrow;
            borrow = 1;
        }
    }
    // 如果borrow仍为1，表示高位借位，但对于P>1000，不可能超过MOD位

    // 输出最后500位，每行50位，高位补0
    for (ll r = 0; r < 10; ++r) {
        for (ll c = 0; c < 50; ++c) {
            ll pos = MOD - 1 - r * 50 - c; // 从高位到低位
            printf("%lld", digits[pos]);
        }
        printf("\n");
    }
    return 0;
}