package com.pjanof.cache.utilities;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.TimeZone;

public class FileDateUtil {
	public native String getLastAccessDate(String fileName);
	public native String getLastModifiedDate(String fileName);
	public native String getLastStatusChangedDate(String fileName);

	public Date formatDate(String format, String timeZone, String date) {
		Date dt = null;
		
		try {
			DateFormat dateFormat = new SimpleDateFormat(format);
			dateFormat.setTimeZone(TimeZone.getTimeZone(timeZone));
			
			dt = dateFormat.parse(date);
		} catch (ParseException e) {
			// do something
		}
		
		return dt;
	}
	
	static {
		System.loadLibrary("FileDateUtil");
	}
}
