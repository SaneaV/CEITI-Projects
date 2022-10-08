function init(){
	document.getElementById("divErrorMessage").style.visibility = "hidden";
}

function check()
{
	let form = document.forms.form;
	let errorMessage = document.getElementById('errorMessage').innerHTML;
	let divErrorMessage = document.getElementById("divErrorMessage");
	errorMessage = "";

	if(form.login.value.length == 0)
	{
		errorMessage = "Вы не указали свой логин" +" <br>";
		divErrorMessage.style.visibility = "visible";
	}
	else if(errorMessage=="")
		divErrorMessage.style.visibility = "hidden";

	let password = form.password.value;
	if(password.length>8 || password.length<4)
	{
		errorMessage += "Пароль должен содержать от 4 до 8 символов" +" <br>";
		divErrorMessage.style.visibility = "visible";
	}
	else if(errorMessage=="")
		divErrorMessage.style.visibility = "hidden";

	if(form['passwordRepeat'].value != password && password.length!=0)
	{
		errorMessage += "Пароль не совпадает" +" <br>";
		divErrorMessage.style.visibility = "visible";
	}
	else if(errorMessage=="")
		divErrorMessage.style.visibility = "hidden";

	if(form.email.value.length == 0)
	{
		errorMessage += invalidEmail();
	}
	else if(errorMessage=="")
		divErrorMessage.style.visibility = "hidden";

	if(form.myTextArea.value.length == 0)
	{
		errorMessage += "Поле о себе не должно быть пустым";
		divErrorMessage.style.visibility = "visible";
	}
	else if(errorMessage=="")
		divErrorMessage.style.visibility = "hidden";

	document.getElementById('errorMessage').innerHTML = errorMessage;

	if(errorMessage=="")
	{
		form.removeEventListener('submit', preventDefault);
	}
	else
	{
		form.addEventListener('submit', preventDefault);
	}
}

function invalidEmail()
{
	return "Вы ввели некорректный e-mail" +" <br>";
}

function preventDefault(e) {
	e.preventDefault();
}
