
//
// Carlos Tojal 14-11-2019
// Ex1
// TesteBuzinar1.java
//

public class TesteBuzinar1 {
	public static void main(String[] args) {
		Citadino citadino = new Citadino();
		Familiar familiar = new Familiar();
		Jipe jipe = new Jipe();

		System.out.println("** Citadino **");
		citadino.buzinar();
		System.out.println(citadino.toString());

		System.out.println("\n** Familiar **");
		familiar.buzinar();
		System.out.println(familiar.toString());

		System.out.println("\n** Jipe **");
		jipe.buzinar();
		System.out.println(jipe.toString());		
	}
}
