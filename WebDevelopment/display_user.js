const worker = new Worker("display_worker.js");

const usersDiv = document.getElementById("users");

async function fetchUsers() {
    try {
        const response = await fetch("https://dummyapi.com/users");

        if (!response.ok) {
            throw new Error("Failed to fetch users");
        }

        const users = await response.json();

        worker.postMessage(users);
    } catch (error) {
        usersDiv.innerHTML = "No users found";
    }
}

worker.onmessage = function (e) {
    if (e.data.error) {
        usersDiv.innerHTML = e.data.error;
        return;
    }

    usersDiv.innerHTML = "";

    e.data.forEach(user => {
        const p = document.createElement("p");
        p.textContent = `${user.name} - ${user.status}`;
        usersDiv.appendChild(p);
    });
};

fetchUsers();
