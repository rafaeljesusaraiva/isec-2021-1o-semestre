var today = new Date();
var n_today = today.getDay(); // 0 é domingo

switch (n_today) {
    case 1:
        $('#segundaFeira').collapse('show');
        break;
    case 2:
        $('#tercaFeira').collapse('show');
        break;
    case 3:
        $('#quartaFeira').collapse('show');
        break;
    case 4:
        $('#quintaFeira').collapse('show');
        break;
    case 5:
        $('#sextaFeira').collapse('show');
        break;
    default:
        break;
}

var horario = JSON.parse($('#jsonFile').html());

showWeek(horario)

function showWeek(horario) {
    for (var dia of Object.keys(horario)) {
        showDay(dia, horario[dia])
    }
}

function showDay(nome, dia) {
    let d = (nome.split('-')[0].toLowerCase()+nome.split('-')[1]).replace('ç', 'c');
    let card = document.getElementById(d);
    let cardBody = document.createElement('div');
    cardBody.className = 'card-body';
    for (var cadeira of Object.keys(dia)) {
        cardBody.appendChild(createCard(dia[cadeira]));
    }
    card.appendChild(cardBody);
}

function createCard(cadeira) {
    let card = document.createElement('div');

    if (cadeira.Tipo.match(/[a-zA-Z]+/g) == "P" || cadeira.Tipo.match(/[a-zA-Z]+/g) == "TP")
        card.className = 'card bg-info my-2';
    else if (cadeira.Tipo.match(/[a-zA-Z]+/g) == "T")
        card.className = 'card bg-success my-2';
    else card.className = 'card bg-dark my-2';

    // Header para Cartao de horario
    let cardHeader = document.createElement('div');
    cardHeader.className = 'card-header';
    cardHeader.innerText = cadeira.Nome + ' ' + cadeira.Tipo;
    cardHeader.appendChild(document.createTextNode('\u00A0'));
    let cardHeader_badge = document.createElement('span');
    cardHeader_badge.className = 'badge badge-danger ml-3';
    cardHeader_badge.innerHTML = cadeira.Horario.Inicio + ' - ' + cadeira.Horario.Fim;
    cardHeader.appendChild(cardHeader_badge);
    cardHeader.appendChild(document.createTextNode('\u00A0'));
    let cardHeader_badge2 = document.createElement('span');
    cardHeader_badge2.className = 'badge badge-secondary ml-1';
    cardHeader_badge2.innerHTML = cadeira.Sala;
    cardHeader.appendChild(cardHeader_badge2);
    card.appendChild(cardHeader);

    // Corpo para Cartao
    let cardBody = document.createElement('div');
    cardBody.className = 'card-body';
    
    // Palavra-passe
    if (cadeira.Password != null) {
        let cardBody_text = document.createElement('p');
        cardBody_text.className = 'card-text';
        let cardBody_text_bold = document.createElement('span');
        cardBody_text_bold.className = 'font-weight-bold user-select-none';
        cardBody_text_bold.innerText = 'Palavra-passe: ';
        cardBody_text.appendChild(cardBody_text_bold);
        let cardBody_text_node = document.createTextNode(cadeira.Password);
        cardBody_text.appendChild(cardBody_text_node);
        cardBody.appendChild(cardBody_text);
    }

    // Botao Link
    if (cadeira.Link != null) {
        let cardBody_button_link = document.createElement('a');
        cardBody_button_link.className = 'btn btn-primary';
        cardBody_button_link.href = cadeira.Link;
        cardBody_button_link.innerText = "Aceder"
        cardBody.appendChild(cardBody_button_link);
    }

    // Botao Registo
    if (cadeira.Registo != null) {
        let cardBody_button_reg = document.createElement('a');
        cardBody_button_reg.className = 'btn btn-primary';
        cardBody_button_reg.href = cadeira.Registo;
        cardBody_button_reg.innerText = "Registar"
        cardBody.appendChild(cardBody_button_reg);
    }

    card.appendChild(cardBody);
    return card;
}