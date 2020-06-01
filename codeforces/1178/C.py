x, y = map(int, input().split())
MOD = 998244353
print( (pow( 2, x + y - 2, MOD ) * 4) % MOD )