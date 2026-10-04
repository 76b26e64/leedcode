
#include <mutex>

class Bank {
private:
    struct account_info {
        long long balance;
        std::mutex lock;
    };

    std::vector<struct account_info> accounts;
    const int account_min = 1;
    int account_max = 1;
    
    inline bool is_valid_account(int account){
        return (account_min <= account && account <= balance.size());
    }

    inline int no_to_index(int account){
        return account - 1;
    }

public:
    Bank(vector<long long>& balance) {
        for (long long b : balance){
            std::mutex m;
            this->accounts.push_back({b, m});
        }
        account_max = balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(!is_valid_account(account1) && !is_valid_account(account2)){
            return false;
        }

        int index1 = no_to_index(account1);
        int index2 = no_to_index(account2);
        std::scoped_lock lock(accounts[index1].lock, accounts[index2].lock);

        if(accounts[index1].balance < money){
            return false;
        }
        if(std::numeric_limits<long long>::max() - accounts[index2].balance < money){
            return false;
        }

        accounts[index1].balance -= money;
        accounts[index2].balance += money;
        return true;
    }
    
    bool deposit(int account, long long money) {

        if(!is_valid_account(account)){
            return false;
        }
        
        int index = no_to_index(account);
        std::scoped_lock lock(accounts[index].lock);

        if(std::numeric_limits<long long>::max() - accounts[index].balance < money){
            return false;
        }

        accounts[index].balance += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!is_valid_account(account)){
            return false;
        }
        
        int index = no_to_index(account);
        std::scoped_lock lock(accounts[index].lock);

        if(accounts[index].balance < money){
            return false;
        }
        
        accounts[index].balance -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
