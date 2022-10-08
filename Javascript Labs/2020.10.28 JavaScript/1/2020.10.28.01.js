function changePrice(){
	let form = document.forms.form;
	let price = 0;

	if(form.ch1.checked)
	{
		price = form.ch1.value;
	}

	if(form.ch2.checked)
	{
		price = +price + +form.ch2.value;
	}

	if(form.ch3.checked)
	{
		price= +price + +form.ch3.value;
	}

	form.total.value = price;
}