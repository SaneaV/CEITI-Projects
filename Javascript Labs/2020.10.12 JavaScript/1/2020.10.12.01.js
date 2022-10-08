function openCloseList(nameClass)
{
	let element = document.querySelector("."+nameClass);
	let index = nameClass.indexOf('-');

	if(element.classList.contains("show-block")) 
	{

		if(nameClass.includes("Class"))
		{
			closeAll(nameClass, 5, index);
		}

		else if(nameClass.includes("Order"))
		{
			closeAll(nameClass, 4, index);
		}

		else if(nameClass.includes("Family"))
		{
			closeAll(nameClass, 3, index);
		}

		else if(nameClass.includes("Genus"))
		{
			closeAll(nameClass, 2, index);
		}
		else if(nameClass.includes("Species"))
		{
			closeAll(nameClass, 1, index);
		}
	}
	else 
	{
		element.classList.add("show-block");
	}
}

function closeAll(nameClass, number, index)
{
	let specific = ["-Species", "-Genus", "-Family", "-Order", "-Class",];

	for(let i=0;i<number;i++)
	{
		if(document.querySelector("."+ nameClass.substring(0, index) + specific[i])!=null)
		{
			let tempClassName = document.querySelector("."+ nameClass.substring(0, index) + specific[i]);
			tempClassName.classList.remove("show-block");
		}

		if(document.querySelector("."+ nameClass.substring(0, index) + specific[i] + "-2")!=null)
		{
			let tempClassName = document.querySelector("."+ nameClass.substring(0, index) + specific[i] + "-2");
			tempClassName.classList.remove("show-block");
		}
		if(document.querySelector("."+ nameClass.substring(0, index) + specific[i] + "-3")!=null)
		{
			let tempClassName = document.querySelector("."+ nameClass.substring(0, index) + specific[i] + "-3");
			tempClassName.classList.remove("show-block");
		}
	}
}