function check(){
	let javaVar = document.getElementById("Java");
	let cPlusVar = document.getElementById("C++");
	let cSharpVar = document.getElementById("C#");
	let onlyLetters = onlyLettersFunc(document.getElementById("Name").value);

	if(!onlyLetters)
	{
		document.forms.information.addEventListener('submit', preventDefault);
		alert("Имя должно состоять из латинских букв!")
	}
	else if(document.getElementById("password").value.length<6)
	{
		document.forms.information.addEventListener('submit', preventDefault);
		alert("Пароль должен быть больше 6 символов!")
	}
	else if(!document.getElementById("Male").checked && !document.getElementById("Female").checked)
	{
		document.forms.information.addEventListener('submit', preventDefault);
		alert("Укажите ваш пол!")

	}
	else if(!javaVar.checked && !cPlusVar.checked && !cSharpVar.checked)
	{
		document.forms.information.addEventListener('submit', preventDefault);
		alert("Укажите язык программирования!")

	}
	else if(document.getElementById("text").value=="")
	{
		document.forms.information.addEventListener('submit', preventDefault);
		alert("Опишите себя!")
	}
	else
	{
		document.forms.information.removeEventListener('submit', preventDefault);
		let newWindow = open("about:blank", "hello", "width=900,height=500");

		newWindow.document.write("<script>alert('Привет!');<\/script>");
		newWindow.document.write("<center>Name: " + document.getElementById("Name").value + "<br><center>");
		newWindow.document.write("<center>Password: " + document.getElementById("password").value+ "<br><center>");
		if(document.getElementById("Male").checked)
			newWindow.document.write("<center>Gender: Male" + "<br><center>");
		else
			newWindow.document.write("<center>Gender: Female" + "<br><center>");
		newWindow.document.write("<center>Age: " + document.getElementById("age").value + "<br><center>");
		newWindow.document.write("<center>Languages: ");
		if(javaVar.checked)
		{
			newWindow.document.write("Java ");
		}
		if(cPlusVar.checked)
		{
			newWindow.document.write("C/C++ ");
		}
		if(cSharpVar.checked)
		{
			newWindow.document.write("C# ");
		}
		newWindow.document.write("<br>");
		newWindow.document.write("About you: "+document.getElementById("text").value + "<br><center>");

		let html = `<div style="font-size:30px"><center>Добро пожаловать!<center></div>`;
		newWindow.document.body.insertAdjacentHTML('afterbegin', html);
		newWindow.document.write(`<center><button type="close" onclick="closeWin()" style="margin-top:5px">Close</button><center>`);
		newWindow.document.write("<script>function closeWin() {window.close();}<\/script>");
	}
}

function preventDefault(e) {
	e.preventDefault();
}

function onlyLettersFunc(str){
	for(let x=0;x<str.length;x++)
	{
		if(!(str.charAt(x) >= 'a' && str.charAt(x) <= 'z') && !(str.charAt(x) >= 'A' && str.charAt(x) <= 'Z'))
			return false;
	}
	if(str.length!=0)
		return true;
	else 
		return false;
}

