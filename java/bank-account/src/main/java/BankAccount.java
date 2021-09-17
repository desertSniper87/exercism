class BankAccount {
    private int currentBalance = 0;

    private boolean isOpen;

    public void open() {
        this.isOpen = true;
    }


    public int getBalance() throws BankAccountActionInvalidException {
        if (!isOpen)
            throw new BankAccountActionInvalidException("Account closed");
        else
            return this.currentBalance;
    }

    public void deposit(int amount) throws BankAccountActionInvalidException {
        if (!isOpen) {
            throw new BankAccountActionInvalidException("Account closed");
        }

        if (amount < 0) {
            throw new BankAccountActionInvalidException("Cannot deposit or withdraw negative amount");
        }

        currentBalance += amount;
    }


    public void withdraw(int amount) throws BankAccountActionInvalidException {
        if (!isOpen) {
            throw new BankAccountActionInvalidException("Account closed");
        }

        if (amount < 0) {
            throw new BankAccountActionInvalidException("Cannot deposit or withdraw negative amount");
        }

        if (amount <= currentBalance) {
            currentBalance -= amount;
        } else {
            if (currentBalance == 0)
                throw new BankAccountActionInvalidException("Cannot withdraw money from an empty account");
            else
                throw new BankAccountActionInvalidException("Cannot withdraw more money than is currently in the account");

        }
    }


    public void close() {
        isOpen = false;
    }
}