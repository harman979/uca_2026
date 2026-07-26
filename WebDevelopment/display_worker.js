self.onmessage = function (e) {
    const users = e.data;

    if (!users || users.length === 0) {
        self.postMessage({ error: "No users found" });
        return;
    }

    const result = users.map(user => ({
        name: user.name,
        status: user.active ? "Active" : "Inactive"
    }));

    self.postMessage(result);
};
