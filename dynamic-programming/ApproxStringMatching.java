package com.topics.algorithms.dynamicProgramming;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class ApproxStringMatching {
	private List<String> foods = new ArrayList<String>();
	private Map<String, Double> matchingScores = new HashMap<String, Double>();
	private Scanner scanner;
	private static double[][] mismatchScoreTable;
	private String in;
	private int inLength;

	public ApproxStringMatching(String text) {
		/*
		 * read the file, fill the food list
		 */
		try {
			scanner = new Scanner(text);
			while (scanner.hasNext()) {
				this.foods.add(scanner.nextLine());
			}
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
		if (mismatchScoreTable == null)
			initMismatchScoreTable();
	}

	public List<String> getFoods() {
		return this.foods;
	}

	private static void initMismatchScoreTable() {
		mismatchScoreTable = new double[256][256];
		/*
		 * Score any combination of two characters as 1 by default.
		 */
		for (int i = 0; i < 256; i++)
			for (int j = 0; j < 256; j++)
				mismatchScoreTable[i][j] = 1.0d;
		/*
		 * If the input charater and reference character are the same, there is no typo.
		 * So the error score is 0.
		 */
		for (int i = 0; i < 256; i++)
			mismatchScoreTable[i][i] = 0.0d;
		/*
		 * For people who use both German keyboard and English keyboard, this typo is
		 * highly frequent.
		 */
		mismatchScoreTable['y']['z'] = 0.1d;
		mismatchScoreTable['z']['y'] = 0.1d;
		mismatchScoreTable['v']['b'] = 0.15d;
		mismatchScoreTable['b']['v'] = 0.15d;
		mismatchScoreTable['n']['m'] = 0.11d;
		mismatchScoreTable['m']['n'] = 0.11d;
		mismatchScoreTable['t']['r'] = 0.15d;
		mismatchScoreTable['r']['t'] = 0.15d;
		mismatchScoreTable['g']['h'] = 0.15d;
		mismatchScoreTable['h']['g'] = 0.15d;
		mismatchScoreTable['y']['u'] = 0.15d;
		mismatchScoreTable['u']['y'] = 0.15d;
		/*
		 * more typo possibilities can be inserted here....
		 */
	}

	public Map<String, Double> getScores(String in) {
		this.in = in;
		this.inLength = in.length();
		for (String food : this.foods) {
			int refLength = food.length();
			double[][] errScore = new double[inLength + 1][refLength + 1];
			errScore[0][0] = 0.0d;
			for (int inCharAt = 1; inCharAt <= this.inLength; inCharAt++)
				errScore[inCharAt][0] = inCharAt;
			for (int refCharAt = 1; refCharAt <= refLength; refCharAt++)
				errScore[0][refCharAt] = refCharAt;
			for (int inCharAt = 1; inCharAt <= inLength; inCharAt++)
				for (int refCharAt = 1; refCharAt <= refLength; refCharAt++) {
					/*
					 * if a character is absent at the given position in the input string, we add
					 * score 1.
					 */
					double charAbsence = errScore[inCharAt - 1][refCharAt] + 1;
					/*
					 * if a character is redundant at the given position in the input string, we add
					 * score 1.
					 */
					double charRedundance = errScore[inCharAt][refCharAt - 1] + 1;
					/*
					 * if it is a matching error, we add the score specified in the score table for
					 * matching errors.
					 */
					double mismatch = errScore[inCharAt - 1][refCharAt - 1]
							+ mismatchScoreTable[this.in.charAt(inCharAt - 1)][food.charAt(refCharAt - 1)];
					/*
					 * initialize the score for swap error to a very big value.
					 */
					double charPositionSwap = 999999d;
					/*
					 * score for swap error
					 */
					if (inCharAt > 1 && refCharAt > 1 && this.in.charAt(inCharAt - 1) == food.charAt(refCharAt - 2)
							&& this.in.charAt(inCharAt - 2) == food.charAt(refCharAt - 1)) {
						/*
						 * the score for typing "ie" as "ei" and vice versa is even lower
						 */
						if (this.in.charAt(inCharAt - 2) == 'e' && this.in.charAt(inCharAt - 1) == 'i') {
							charPositionSwap = errScore[inCharAt - 2][refCharAt - 2] + 0.25;
						}
						/*
						 * more cases can be inserted here.
						 */
						else
							charPositionSwap = errScore[inCharAt - 2][refCharAt - 2] + 0.5;
					}
					/*
					 * more error cases can be inserted here.
					 */
					double minScore = mismatch;
					if (charAbsence < minScore) {
						minScore = charAbsence;
					}
					if (charRedundance < minScore) {
						minScore = charRedundance;
					}
					if (charPositionSwap < minScore) {
						minScore = charPositionSwap;
					}
					errScore[inCharAt][refCharAt] = minScore;
				}
			this.matchingScores.put(food, errScore[this.inLength][refLength]);
		}
		return this.matchingScores;
	}

	@SuppressWarnings({"unchecked", "rawtypes"})
	public static void main(String[] args) {
		String text = "In computer science, approximate string matching "
				+ "(often colloquially referred to as fuzzy string searching) is the technique of finding strings that match a pattern approximately (rather than exactly). "
				+ "The problem of approximate string matching is typically divided into two sub-problems: finding approximate substring matches inside a given string and finding "
				+ "dictionary strings that match the pattern approximately.";
		Scanner sc = new Scanner(System.in);
		ApproxStringMatching demo = new ApproxStringMatching(text);
		System.out.print("Please type a word. Type q for exit: ");
		sc.nextLine();
		while (sc.hasNext()) {
			String in = sc.nextLine();
			if (in.equals("q")) {
				System.exit(0);
			}
			System.out.println("You typed " + in);
			System.out.println("--------------------------------------------");
			Map scoreMap = demo.getScores(in);
			for (String food : demo.getFoods()) {
				System.out.println(food + "\t error score: " + scoreMap.get(food));
			}
			System.out.println("--------------------------------------------");
			double minScore = (Double) Collections.min(scoreMap.values());
			if (minScore == 0.0d) {
				System.out.println(in + " is in the list.");
			} else {
				List<String> corrections = new ArrayList<String>();
				StringBuffer sb = new StringBuffer("Do you mean:- ");
				for (String food : demo.getFoods()) {
					if (scoreMap.get(food).equals(minScore)) {
						corrections.add(food);
						sb.append(food).append(" or ");
					}
				}
				sb.append("?");
				System.out.println(sb.toString());
			}
			System.out.println("Please type a word. Type q for exit: ");
		}
		sc.close();
	}
}