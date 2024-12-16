import model.Chocolate;
import model.Lollipop;
import model.Sweet;
import service.Gift;
import util.GiftLoader;
import util.SweetComparators;

import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Gift gift = new Gift();

        try {
            gift = GiftLoader.loadGiftFromFile("./input.txt");
            System.out.println("Present was loaded from file.");
        } catch (Exception e) {
            System.out.println("File loading error.");
        }

        while (true) {
            System.out.println("\n1. Show present");
            System.out.println("2. Add chocolate");
            System.out.println("3. Add lollipop");
            System.out.println("4. Sort by weight");
            System.out.println("5. Find sweets by sugar");
            System.out.println("6. Show total gift weight");
            System.out.println("0. Exit");

            int choice = scanner.nextInt();
            switch (choice) {
                case 1: {
                    gift.displaySweets();
                    break;
                }
                case 2: {
                    System.out.println("Input: Name, Weight, Sugar, Type");
                    String name = scanner.next();
                    double weight = scanner.nextDouble();
                    double sugar = scanner.nextDouble();
                    Chocolate.Type type = Chocolate.Type.valueOf(scanner.next());
                    gift.addSweet(new Chocolate(name, weight, sugar, type));
                    break;
                }
                case 3: {
                    System.out.println("Input: Name, Weight, Sugar, Color");
                    String name = scanner.next();
                    double weight = scanner.nextDouble();
                    double sugar = scanner.nextDouble();
                    Lollipop.Color color = Lollipop.Color.valueOf(scanner.next());
                    gift.addSweet(new Lollipop(name, weight, sugar, color));
                    break;
                }
                case 4: {
                    gift.sortSweets(SweetComparators.byWeight());
                    System.out.println("Sort by weight");
                    break;
                }
                case 5: {
                    System.out.println("Input sugar range:");
                    double min = scanner.nextDouble();
                    double max = scanner.nextDouble();
                    List<Sweet> sweets = gift.findSweetsBySugarRange(min, max);
                    sweets.forEach(System.out::println);
                    break;
                }
                case 6: {
                    System.out.println("Общий вес подарка: " + gift.getTotalWeight());
                    break;
                }
                case 0: {
                    System.out.println("Выход.");
                    return;
                }
            }
        }
    }
}