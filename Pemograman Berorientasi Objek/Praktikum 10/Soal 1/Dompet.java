/* NIM/Nama	 : 13517137/Vincent Budianto
 * Nama File : Dompet.java
 * Topik     : Praktikum 10
 * Tanggal   : 04 April 2019
 * Deskripsi : Kelas Dompet */

import java.util.*;

public class Dompet<T extends Number> {
    private ArrayList<Transaction> transactions;


     public Dompet() {
        // Constructor tanpa parameter, transactions diinisialisasi dengan array list baru
        this.transactions = new ArrayList<Transaction>();
    }


    public Dompet(T initialBalance) {
        // Constructor dengan parameter T initialBalance, inisialisasi transactions dengan array list baru dan tambahkan transaksi tambah dengan value initial balance
        /* contoh transaksi tambah: new Transaction<T>('+', initialBalance) */
        this.transactions = new ArrayList<Transaction>();
        this.transactions.add(new Transaction('+', initialBalance));
    }

    public void addMoney(T money) {
        // Buat prosedur addMoney dengan parameter T money, tambahkan transaksi tambah dengan senilai money
        this.transactions.add(new Transaction('+', money));
    }

    public boolean takeMoney(T money) {
        // Tambahkan transaksi kurang sebesar money (perlu ada pengecekan apakah balance cukup atau tidak)
        // false bila transaksi gagal, true bila berhasil
        if (this.getBalance().doubleValue() >= money.doubleValue())
        {
			this.transactions.add(new Transaction('-', money));
			return true;
		}
		else
		{
			return false;
		}
    }

    public void setBalance(T balance) {
        // Mengganti transaksi agar bernilai sama dengan balance
        // Tips: inisialisasi ulang transactions, lalu tambahkan transaksi tambah sebanyak balance
        this.transactions = new ArrayList<Transaction>();
        this.transactions.add(new Transaction('+', balance));
    }

    // Akses nilai Double dilakukan dengan .doubleValue()
    // Contoh: amount.doubleValue()

    public Double getBalance(){
        // Mencari balance dompet dari transaksi dengan cara menghitung total transaksi
        Double total;
        int i;
        
        total = 0.00;
        
        for (i = 0; i < this.transactions.size(); i++)
        {
			if (transactions.get(i).getType() == '+')
			{
				total += transactions.get(i).getAmount().doubleValue();
			}
			else if (transactions.get(i).getType() == '-')
			{
				total -= transactions.get(i).getAmount().doubleValue();
			}
		}
        
        return (total);
    }

    public void printTransactions() {
        // Print seluruh transaksi yang ada pada array
        // Format: Transactions [indeks + 1]: [tipe transaksi] [amount]
        // Contoh: Transactions 3: + 500
        int i;
        
        for (i = 0; i < this.transactions.size(); i++)
        {
			System.out.println("Transactions " + (i + 1) + ": " + this.transactions.get(i).getType() + " " + this.transactions.get(i).getAmount());
		}
    }

    public Double getAverageTransaction() {
        // Mencari rata-rata transaksi (jika tidak ada transaksi, berikan hasil null)
        if (this.transactions.size() == 0)
        {
			return null;
		}
		else
		{
			return (this.getBalance() / this.transactions.size());
		}
    }

    public Double getMinimumTransaction() {
        // Mencari nilai minimum transaksi (jika tidak ada transaksi, berikan hasil null; hanya perlu membandingkan nilainya saja tanpa peduli type)
        Double min;
        int i;
        
        if (this.transactions.size() == 0)
        {
			return null;
		}
		else
		{
			min = this.transactions.get(0).getAmount().doubleValue();
			
			for (i = 1; i < this.transactions.size(); i++)
			{
				if (min > this.transactions.get(i).getAmount().doubleValue())
				{
					min = this.transactions.get(i).getAmount().doubleValue();
				}
			}

			return (min);
		}
    }

    public Double getMaximumTransaction() {
        // Mencari nilai maksimum transaksi (jika tidak ada transaksi, berikan hasil null; hanya perlu membandingkan nilainya saja tanpa peduli type)
        Double max;
        int i;
        
        if (this.transactions.size() == 0)
        {
			return null;
		}
		else
		{
			max = this.transactions.get(0).getAmount().doubleValue();
			
			for (i = 1; i < this.transactions.size(); i++)
			{
				if (max < this.transactions.get(i).getAmount().doubleValue())
				{
					max = this.transactions.get(i).getAmount().doubleValue();
				}
			}

			return (max);
		}
    }
}
