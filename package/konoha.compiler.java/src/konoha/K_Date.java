package konoha;

import java.util.Calendar;

public class K_Date extends K_Object {
	
	private final Calendar calendar = Calendar.getInstance();
	
	public void _new(int year, int month, int date, int hourOfDay, int minute, int second) {
		calendar.set(year, month, date, hourOfDay, minute, second);
	}
	
	public String castString() {
		return calendar.toString();
	}
	
}
