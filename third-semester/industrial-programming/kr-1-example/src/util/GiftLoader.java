package util;

import model.*;
import service.Gift;

import java.io.*;
import java.util.*;

public class GiftLoader {
    public static Gift loadGiftFromFile(String filePath) throws IOException {
        Gift gift = new Gift();
        BufferedReader reader = new BufferedReader(new FileReader(filePath));

        String line;
        while ((line = reader.readLine()) != null) {
            String[] parts = line.split(" ");
            switch (parts[0].trim()) {
                case "Chocolate":
                    gift.addSweet(new Chocolate(parts[1], Double.parseDouble(parts[2]),
                            Double.parseDouble(parts[3]), Chocolate.Type.valueOf(parts[4])));
                    break;
                case "Lollipop":
                    gift.addSweet(new Lollipop(parts[1], Double.parseDouble(parts[2]),
                            Double.parseDouble(parts[3]), Lollipop.Color.valueOf(parts[4])));
                    break;
            }
        }
        return gift;
    }
}
